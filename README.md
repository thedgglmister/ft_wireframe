# ft_wireframe
The 1st project of the 42us graphics branch

### --Project Description--
ft_wireframe is a wireframe renderer that can display 3D wireframe models in color and with the option of hidden surface removal. The coordinates and colors of vertices are specified in an input file, points are transformed using an isometric projection, and then Bresenham's line drawing and rasterization algorithms are used to draw pixels. Additonally, the model can be rotated, translated, and dilated using key controls. Hidden surface removal is accomplished using a z-buffer and can be optionally disabled using the -T flag.

### --Coding Style--
At 42, we follow a strict norm in order to teach us to follow style guides. This norm also prevents us from using many built-in functions. In this project, we are limited to using a barebones graphic library called minilibx. This library limits the functionality to creating windows, handling input hooks, and coloring specific pixels.

The allowed functions are : ```exit, open, close, write, read, malloc, free, and the functions of minilibx and math.h```.

The Project is written in C and in accordance with "The Norm".

#### --The Norm--
    • Functions must not exceed 25 lines
    • No more than 5 function-definitions in a .c file
    • One instruction per line
    • One single variable declaration per line; cannot stick declaration and initialisation on the same line
    • No more than 5 variables per bloc
    • No more than 4 parameters per function
    • Forbidden functions are: [for] [do ... while] [switch] [case] [goto]
    
### --Demo Instructions (Mac OSX Sierra)--

    • Open Terminal and run the following commands:
    • git clone https://github.com/thedigglemister/ft_wireframe ft_wireframe
    • cd ft_wireframe
    • make && ./wireframe maps/volcano.fdf

#### --User Controls--
    • Left/Right arrows rotate about models y-axis, Up/Down arrows rotate about models x-axis
    • W,A,S,D are used to translate the model
    • Z,X can be used to zoom in and out
    • esc to exit
   
#### --Flag Usage--

    ./wireframe [-T | -C [hex >= 0]] [-W [int > 0]] file
       -T --transparent
       -C --fill_color
       -W --window_size
      
<img src="/images/volcano.png" width="800">
<img src="/images/42.png" width="600">
