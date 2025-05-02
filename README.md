# 18-224/624 S25 Tapeout Template

## InlineVGA

### Description
InlineVGA is an ASIC that receives image data in VGA format. The data is modified (exact transformations not decided)
and then passed to a VGA monitor as the output. The ASIC  works in a relatively streaming fashion with 
data buffering as needed. The circuit will  sit “inline” with input  signals coming directly from a VGA cable and the output
going to the D connector of a VGA monitor. The module is assumes a 640 x 480 input image.  

### High Level Design
InlineVGA is roughly broken into four distinct components with some smaller auxiliary modules. More about the auxiliary components 
can be inferred from the provided source code. The four main modules are briefly described here in terms of their input and output 
signals and functional responsibilities.

The Source Monitor will handle tracking all the state information from the incoming VGA cable. This included the pixel row and 
column, and most importantly horizontal and vertical syncs. The module will communicate with the Output Monitor. It will receive 
inputs from incoming VGA horizontal and vertical syncs and will output to the Output Monitor.

Similar to the Source Monitor, the Output Monitor will track the state of data that is being passed to the outgoing VGA cable. 
It includes the outgoing version of the information mentioned above. In addition, it will control the queueing logic of the 
Pixel Buffer. There will be moments where the outgoing VGA is in the front or back porch and not consuming the pixel data passed 
by the incoming VGA. During these periods the incoming pixel data will need to be buffered until it is ready to be dispatched. 
The module will communicate with Pixel Buffer and D connector directly. It will receive inputs from the Source Monitor and output 
to the Pixel Buffer, outgoing horizontal and vertical syncs, and an error signal.

The Pixel Editor handles the execution of different pixel transforms. The implemented transforms are monochromatic filters for RGB, 
gray scaling, and RGB rotating. The inputs of the module will be the digital version of the incoming RGB values and the output will 
be the Pixel Buffer. Selecting the desired filter is handle by sequential shiting in a 3-bit sequence on the cmd_bit pin of the chip.

The Pixel Buffer will handle passing the modified pixel values to DAC and eventually the outgoing VGA cable. Additionally, the module 
is responsible for queueing RGB values when the outgoing VGA is not consuming pixel data (i.e front and back porch, and sync pulse), 
but the incoming VGA is producing pixel data. The module will take input from the Pixel Editor and the Output Monitor and will output 
the ongoing RGB values to DAC and eventually the VGA cable.

### IO

An IO table listing all of your inputs and outputs and their function, like the one below:

| Input/Output| Description                                         |																
|-------------|-----------------------------------------------------|
| io_in[0]    | i_cmd_bit - pin used for shfiting desire transform  |
| io_in[3:1]  | i_blue - src vga blue color value                   |
| io_in[6:4]  | i_green - src vga green color value                 |
| io_in[9:7]  | i_red - src vga red color value                     |
| io_in[10]   | i_vsync - src vga verticla sync                     |
| io_in[11]   | i_hsync - src vga horizontal sync                   |

| Input/Output| Description                                         |																
|-------------|-----------------------------------------------------|
| io_out[0]   | o_error - indicates the module is in an error state |
| io_out[3:1] | o_blue - outgoing vga blue color value              |
| io_out[6:4] | o_green - outgoing vga green color value            |
| io_out[9:7] | o_red - outgoing vga red color value                |
| io_out[10]  | o_vsync - outgoing vga verticla sync                |
| io_out[11]  | o_hsync - outgoing vga horizontal sync              |


### How to Test
Most of the data ports necessary are handle implictly through the incoming VGA pmod and outgoing VGA pmod. The only manual testings
that must be carried out by a microcontroller is inputting the sequence of command bits as seen in the mappings below. The values are
shifted in 1 bit per clock cycle and every 3rd clock cycle the transform will be updated to the most recently shifter 3-bit sequence.
If no values are provided for the cmd_bit, the ASIC will serve as a passthrough of the incoming VGA signal without and modifications.
Additionally, it is in the expected behavior that InlineVGA will miss the first frame of the incoming signal as a result of needing 
to synchronize with the incoming signal. If any errors occur the error signal will be asserted, but the ASIC does not have self-handling
error correct path. The unit must be manually reset usin the provide reset pin. InlineVGA is designed using ACTIVE NEGATIVE reset logic.

| Input/Output| Bit Sequnece             | Description                   |																
|-------------|--------------------------|-------------------------------|
| NONE        | 3'b000 / 3'b110 / 3'b111 | Passthrough of src VGA Signal |
| ISO_BLUE    | 3'b001                   | Block src non-blue channels   |
| ISO_GREEN   | 3'b010                   | Block src non-green chaneels  |
| ISO_RED     | 3'b011                   | Block src non-red channels    |
| RGB_ROTATE  | 3'b100                   | Cyclic RGB value shift left   | 
| GRAY_SCALE  | 3'b101                   | Average src RGB values        |
