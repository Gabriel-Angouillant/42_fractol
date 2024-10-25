## Fract-ol
### About the 42 Norm:
- Each file must contain no more than 5 functions.
- Each function must not exceed 25 lines.
- The project must be written solely in C.
- Global variables are not allowed.
- Allowed external functions are: `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`, and functions from the `<math.h>` library.

### Project Overview:
This project aims to create a dynamic **fractal exploration software**. A fractal is a complex geometric shape that contains patterns which repeat infinitely at any scale.
These fractals are computed from complex numbers, giving the project a strong mathematical part. **Mandelbrot**, **Julia**, and **Burning Ship** fractals are available. 

Infinite zooming in and out is possible within each fractal, limited only by the machine's capabilities. Users can apply different color sets and adjust the color display types.

During runtime, users can switch between fractals, save a specific position in memory, modify the rendering of the Julia set, pixelize the rendering for better performance, and increase or reduce the precision of the fractal.

This project uses the graphical library [MacroLibX](https://github.com/seekrs/MacroLibX), a rewrite of the 42 MiniLibX.

## Preview:

### Mandelbrot
![image](https://github.com/user-attachments/assets/9f3f156d-2c8b-4438-9ec9-1759f24399d1)

### Julia
![image](https://github.com/user-attachments/assets/e0580c3d-6030-49f5-9038-eda039b02232)

### Burning ship
![image](https://github.com/user-attachments/assets/93ff1a0d-963c-410e-9d1f-57a77b73a81e)

### Bindings
![image](https://github.com/user-attachments/assets/228cc2df-207e-471e-ac6d-0d6dca47f20a)
