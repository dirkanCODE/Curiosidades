Permite ampliar y reducir pulsando sobre la zona deseada con el raton, con botón izquierdo y botón derecho respectivamente.

Algunas capturas de la salida que produce el código:

Por aquí dejo una variante con 2500 iteraciones para la sucesión en cada punto:

Color:
```c 
if (x<0)
  glColor3f(0,color*y*y/15,color*(-x)/25);
else
  glColor3f(color*x/5,color*y*y/15,0);
```
  
![image](https://user-images.githubusercontent.com/87771600/131711114-010991f6-d7f3-487b-bfed-c0b54aaedab8.png)

Algunas otras capturas:

![image](https://user-images.githubusercontent.com/87771600/131711467-8242bef1-282b-4853-a281-1ad043f53513.png)
![image](https://user-images.githubusercontent.com/87771600/131711494-ae3afa85-d2dc-45fb-9fc2-c4c62ad64c1b.png)
![image](https://user-images.githubusercontent.com/87771600/131711523-a76ea16f-147d-4c64-9c59-c74181983027.png)
![image](https://user-images.githubusercontent.com/87771600/131711536-2c7b0d1f-52b5-4f54-90ec-f7b7af02033f.png)

