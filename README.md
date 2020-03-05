
******************************************* 

**En que consiste DesignApp:** 

Es una aplicación diseñada tanto para IOS como para Android.
Esta aplicación está conectada a una base de datos y a un Servidor via websocket. Los mensajes que se envían y se reciben son mensajes JSON.
Consiste en poder subir fotos relacionadas con tus looks que más te gusten y así poder mostrarlos a tus seguidores y darle me gusta y también poder comentar.
La aplicación la puedes encontrar subida en GitHub.
**Como se ha ido haciendo el proyecto (que tecnología he utilizado)**

Mi proyecto se ha realizado en el sistema operativo Linux.
En la parte técnica, DesignApp es una aplicación que está orientada a objetos. Está dividida con una clase Servidor y las diferentes clases que contiene la aplicación(usuario,foto,estilo y comentarios)
Para hacer la conexión entre el Servidor y el cliente , he utilizado websocket para poder conectar mi Servidor con el cliente, lo he ido haciendo via mensajes JSON.
Para el diseño de la aplicación he ido utilizando html, css y javascript
Cada vez que he ido actualizando todo lo que hago o modifico de la aplicación ,lo he ido guardando en el git (Git es un software de control de versiones), pero para utilizar
el git lo he tenido que instalar en mi máquina virtual.
He creado una base de datos en PostgreSQL para poder ir guardando la información.

Resumido:

- PostgreSQL para base de datos


- Websocket para conectar el servidor con el cliente


- Html,css y javascript para su diseño y funcionalidad


- Git para ir guardando los cambios


- Mensajes JSON

*********************************************************************************************
**Ejemplos para poder utilizar la aplicación sin estar registrado**

1) Una vez instalada la aplicación o descargada de github, puedes probar la aplicación sin tener que registrarte. Hay un usuario creado, con el cuál puedes acceder.
usuario : Pepa@gmail.com contraseña :1234
2)La base de datos se llama DesignApp.


*********************************************************************************************
**Pasos para poder utilizar la aplicación:**


1) Una vez instalada la aplicación en el teléfono , al usuario se le abrirá la página de Login. En esta página, el usuario podrá acceder a su cuenta indicando su email y contraseña. 

2) En el caso de que el usuario no esté registrado podrá crearse una cuenta haciendo click en el botón que se encuentra justo debajo del OK.

3) Al conectarse con su email y contraseña, le aparecerá la página principal de la aplicación, que es donde aparecen todas las fotos subidas de los seguidores del usuario.
Es decir, las actualizaciones más recientes. Además, se puede ver perfectamente los iconos de like y comentario. Al clickar en el icono del comentario se desplazará hacia abajo
una nueva pestaña en la cuál podrás dejar un comentario.

4) En el header de la aplicación se podrán ver las opciones de buscar usuarios. 
 Se podrá acceder al perfil de esa persona y ver las fotos subidas con sus comentarios y likes y sus seguidores.
 Además en la página principal, en el propio header habrá un icono de entrar en el propio perfil de la persona que ha iniciado sesión.

5) Al estar en tu perfil, podrás ver que te aparecerá el icono de una cámara. Al clickar en el icono de la cámara ,
 se abrirá una ventana en la cual puedes insertar la URL de tu imagen y poner de qué tipo es.
 
************************************************************** 
**Otras opciones que me gustaría que tuviera mi proyecto:**


1) Lo más importante que me habría gustado implementar en mi proyecto es que en vez de que se guarde la URL de una foto se guarde la imagen.

2) Me habría gustado que al darle clic al botón "me gusta" se vaya actualizando en la base de datos y además vaya cambiando de color el icono.

3) Al darle a enviar comentario se guarda en la base de datos pero no se recarga todavía en la aplicación.

4) No se pueden buscar  los usuarios registrados porque debería hacerle a cada uno un perfil propio.

*********************************************************************************************
### Gestión de errores:

Antes de comentar los errores que he tenido a lo largo de la creación de la aplicación, quiero destacar que las posibles dudas o problemas que me han ido surgiendo los he ido solucionando con la ayuda de mi profesor, buscando por Internet y mirando la documentación.

Los errores:

-Problemas a la hora de conectar mi servidor con el cliente.

-Al principio no sabía como hacer los mensajes JSON y me costó bastante coger el hilo:
Un fallo de estos por ejemplo es que hacía el mensaje JSON pero no se enviaba al cliente o el servidor no lo recibía

-He tenido que buscar mucha información de cómo poder ir guardando todo en la bbdd cada vez que creaba un usuario, por ejemplo.
 
Páginas utilizadas para buscar información:

Stack OverFlow
 
### Desarrolladora y diseñadora de DesignApp: Bozhena Stefanova Todorova
