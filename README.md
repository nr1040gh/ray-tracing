# ray-tracing
![Alt text](/imgs/sphere_screen_shot.png "Ray-Casting on Sphere")
Ray-tracing implementation for C++ using native libraries. This has been done many times before but I wanted to do my own implementation of it without referencing any other's code. **Currently, the program is able to successfully implement ray-casting on a sphere with zero perpective** (orthoganal rays to viewing plane) and is oriented with a left-handed coordinate system (positive y "up", positive x "right", positive z "out"). Currently the graphics are displayed in the terminal with ASCII graphics.  

The current characters are:  
" ", ".", "-", "=", "o", "O", "Q", "0"   
in order of ascending brightness

## Limitations
Currently, the rays from the viewing plane come out perpendicular to it; there is no perspective added. The math used to calculate normal vectors and sphere detection by a ray are only valid for a sphere as well. The light source is also a point light source. All of these limitations greatly decrease the complexity of the math involved and allows us to do the calculations by using simple vector operations.  

We also only shoot one ray for each pixel of the viewing display from the "center" of the pixel. In the future, we could add rays from each corner to hopefully smooth the result further.

The graphics are displayed using ascii characters for each pixel on the viewing screen. Since the character space on the terminal is longer than it is wide for each character, I double the character used for the pixel in order to avoid an egg-shaped sphere. For example, for every pixel that is caluclated to be a "O" will be printed into the terminal as "OO" instead.

## To-Do
* Reformat / refractor code.
* Using the current functionality, animate the light source revolving around the sphere with ASCII animation.
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
