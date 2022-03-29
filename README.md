# ray-tracing
![Alt text](/imgs/sphere_screen_shot.png "Ray-Casting on Sphere")
Ray-tracing implementation for C++ using as close as to native libraries as possible. This has been done many times before but I wanted to do my own implementation of it without referencing any other's code. **Currently, the program is able to successfully implement ray-casting on a sphere with zero perpective (orthoganal rays to viewing plane). The window displays an animated sphere with a light source revolving around it, rendered as ASCII art in the terminal.** 

I use a cartesian coordinate system oriented with a left-handed rule (positive y "up", positive x "right", positive z "out"). To revolve the light source around the sphere, I used a spherical coordinate system (using physics convention of azimuthal being phi and polar being theta) centered at the sphere. 

The current characters are:  
" ", ".", "-", "=", "o", "O", "Q", "0"   
in order of ascending brightness

## How to Use  
To compile the program I used g++. You may need to substitute the `g++` command using the appropriate program and the `/` or `\` depending on your operating system. For compiling and linking the program:
1. `cd` into the `src` folder
2. run `g++ main.cpp point.cpp sphere.cpp display.cpp light_source.cpp ray_cast.cpp print_graphics.cpp vector_ops.cpp -o main`
3. run `./main.exe` 

## Limitations
Currently, the rays from the viewing plane come out perpendicular to it; there is no perspective added. The math used to calculate normal vectors and sphere detection by a ray are only valid for a sphere as well. The light source is also a point light source. All of these limitations greatly decrease the complexity of the math involved and allows us to do the calculations by using simple vector operations.  

We also only shoot one ray for each pixel of the viewing display from the "center" of the pixel. In the future, we could add rays from each corner to hopefully smooth the result further.

The graphics are displayed using ascii characters for each pixel on the viewing screen. Since the character space on the terminal is longer than it is wide for each character, I double the character used for the pixel in order to avoid an egg-shaped sphere. For example, for every pixel that is caluclated to be a "O" will be printed into the terminal as "OO" instead.

## To-Do
* Reformat / refractor code.
* Update documentation
* Project rays from corners of pixel and average intensity
* Add perspective.
* Add additional objects.
* Add reflection with those objects.
* Add environment.
* Project image onto sphere and change intensity of image on sphere.

## Inspiration / similar projects:
https://www.quora.com/How-do-I-color-a-sphere-in-computer-graphics-using-C-without-external-libraries - Vladislav Zorov's response

https://www.youtube.com/watch?v=QkETiyYWh2o
https://youtu.be/A-yAkqONnuU
https://youtu.be/bDpXw1_FVRg
https://youtu.be/ZYGJQqhMN1U
https://youtu.be/hYMZsMMlubg

## Reference material
https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection for normal vector of sphere
https://www.povray.org/documentation/3.7.0/t2_2.html for coordinate system
https://www.youtube.com/watch?v=gBPNO6ruevk background info
https://www.youtube.com/watch?v=Ahp6LDQnK4Y background info
https://www.quora.com/How-do-I-color-a-sphere-in-computer-graphics-using-C-without-external-libraries Vladislav Zorov's explanation of brightness
