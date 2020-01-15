
let socket = new WebSocket("ws://127.0.0.1:9990");

var g_idMessage = 0;

function getIdMessage()
{
   g_idMessage++;
   return g_idMessage;
}

socket.onopen = function(e) {
    console.log("Conexión abierta");
};

socket.onmessage = function(event) {

    console.log(event.data);

};

socket.onclose = function(event) {
    console.log("Conexión cerrada");
};

socket.onerror = function(error) {
    console.log("Error");
};

function userList()
{

    var idMensaje = getIdMessage();
    var listaUsuarios = {action:"listaUsuarios", id:idMensaje};
    socket.send(JSON.stringify(listaUsuarios));

}

function photoList()
{

   var idMensaje = getIdMessage();
   var listaFotos = {action:"listaFotos",id:idMensaje};
   socket.send(JSON.stringify(listaFotos));

}

function deletePhoto()
{

      var idMensaje = getIdMessage();
      var fotosEliminadas = {action:"fotosEliminadas",id:idMensaje};
      socket.send(JSON.stringify(fotosEliminadas));

}

function createUser(nombre,correoElectronico,contrasenya)
{

   var idMensaje = getIdMessage();
   var name = nombre;
   var email = correoElectronico;
   var password = contrasenya;

   var crearUsuario = {action:"crearUsuario",id:idMensaje,nombre:name,correoElectronico:email,contrasenya:password};
   socket.send(JSON.stringify(crearUsuario));

}


function login(correoElectronico,contrasenya)
{

   var email = correoElectronico;
   var contrasenya = password;
   
   var entrar = {action:"entrar",email:email,contrasenya:password};
   socket.send(JSON.stringify(entrar));

}


function logout()
{


}

