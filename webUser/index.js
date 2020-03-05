class User {

    constructor(id, name, email, password)
    {
        this._id=id;
        this._name=name;
        this._email=email;
        this._password=password;
    }
    
    get id()
    {
        return this._id;
    }
    
      get name()
    {
        return this._name;
    }
    
      get email()
    {
        return this._email;
    }
    
}

var user;

let socket = new WebSocket("ws://localhost:9990");

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
    
    var mensaje = JSON.parse(event.data);
    if (mensaje.action == "login")
    {
      
        if(mensaje.nombre=="")
        {
            document.getElementById("errorContra").style.display="block";
        }
        else {
            document.getElementById("sectionLogin").style.display="none";
            document.getElementsByClassName("best")[0].style.display="block";
            document.getElementById("indexfot").style.display="flex";
            document.getElementById("buscar").style.display="inline";
            document.getElementById("salir").style.display="block";
            
            user= new User(mensaje.id, mensaje.nombre, mensaje.email,mensaje.password);
            
        }
        
        
        
    }
    if (mensaje.action == "registrar")
    {
      
        document.getElementsByClassName("registro")[0].style.display="none";
        document.getElementsByClassName("best")[0].style.display="block";
        document.getElementById("indexfot").style.display="flex";
        document.getElementById("buscar").style.display="inline";
        document.getElementById("salir").style.display="block";
        
        user= new User(mensaje.id, mensaje.nombre, mensaje.email,mensaje.password);
        
    }
    
    if (mensaje.action == "searchUser")
    {
        
        document.getElementById("buscarUsuarioSection").style.display="block";
        document.getElementsByClassName("best")[0].style.display="none";
        document.getElementById("buscarUsuario").style.display="block";
        document.getElementById("headerPrincipal").style.display="none";
        
    }
    
    if (mensaje.action == "subirFoto")
    {
        document.getElementById("FotosubidaExito").style.display="block";
    }
    
    if (mensaje.action == "listacomentarios")
    {
        
        var figure = document.getElementById("foto"+mensaje.lista[0].idphoto);
        var figcaption = figure.childNodes[3];
        var divComentario = figcaption.childNodes[7];
        
        for (var i of mensaje.lista)
        {
            divComentario.innerHTML += i.comment + "<br/>";
        }
        
    }
    

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

function createUser()
{

   var idMensaje = getIdMessage();
   var name = document.getElementById("nameUsuario").value;
   var email = document.getElementById("emailUsuario").value;
   var password = document.getElementById("contraUsuario").value;
   
    if (name == "" || email == "" || password == "")
    {
        
        
    }else {
        var crearUsuario = {action:"crearUsuario",id:idMensaje,nombre:name,correoElectronico:email,contrasenya:password};
   socket.send(JSON.stringify(crearUsuario));
    }

   

}


function login()
{
    
   var email = document.getElementById("email").value;
   var contrasenya = document.getElementById("pass").value;
   
   var entrar = {action:"entrar",email:email,contrasenya:contrasenya};
   socket.send(JSON.stringify(entrar));

   
}

function register()
{
    
    document.getElementById("sectionLogin").style.display="none";
    document.getElementsByClassName("registro")[0].style.display="block";
    
}


function searchUser()
{
    var name = document.getElementById("buscarTxt").value;
    
    var usuarioEncontrado = {action:"buscar",Buscar:name};
    socket.send(JSON.stringify(usuarioEncontrado));
    
}

function like()
{
    var like = document.getElementsByClassName("far fa-heart").value;
    
    var likePhoto = {action:"like",Like:like};
    socket.send(JSON.stringify(likePhoto));
}

function comment()
{
    var comment = document.getElementsByClassName("far fa-comment").value;
    
    var commentPhoto = {action:"comment",Coment:comment};
    socket.send(JSON.stringify(commentPhoto));
    
}

function subirImagen()
{
    var photo = document.getElementById("imagen").value;
    var style = document.getElementById("Estilo").value;
    var id = user.id;
    
    var subirFoto = {action:"subirFoto",imagen:photo,estilo:style, idUser:id};
    socket.send(JSON.stringify(subirFoto));
}

function PerfilUsuario()
{
        document.getElementById("PerfilUser").style.display="block";
        document.getElementsByClassName("best")[0].style.display="none";
        document.getElementById("headerPerfilUsuario").style.display="block";
        document.getElementById("headerPrincipal").style.display="none";
}


function subirFoto()
{
        document.getElementById("FotoYtipo").style.display="flex";
        document.getElementsByClassName("best")[0].style.display="none";
        document.getElementById("headerPerfilUsuario").style.display="block";
        document.getElementById("headerPrincipal").style.display="none";
}

function CerrarSubirImagen()
{
    document.getElementById("FotoYtipo").style.display="none";
    
}

function Home()
{
    document.getElementById("buscarUsuario").style.display="none";
    document.getElementById("buscarUsuarioSection").style.display="none";
    document.getElementsByClassName("best")[0].style.display="block";
    document.getElementById("headerPrincipal").style.display="block";
}


function HomePerfilUsuario()
{
    document.getElementById("headerPerfilUsuario").style.display="none";
    document.getElementById("PerfilUser").style.display="none";
    document.getElementsByClassName("best")[0].style.display="block";
    document.getElementById("headerPrincipal").style.display="block";
}



function ClickComentario(clickId)
{
    
    
    var parent = clickId.parentElement;
    
    var comentario = parent.childNodes[9];
    if(comentario == null)
    {
        var node = document.createElement("DIV");
        node.setAttribute("class", "comentario");
        
        var titulo = document.createElement("H3");
        titulo.innerHTML = "Nuevo comentario:";
        node.appendChild(titulo);
        
        var input = document.createElement("INPUT");
        input.type = "text"
        input.placeholder = "comentario.."
        input.setAttribute("id", "coment");
        node.appendChild(input);
        
        var buton = document.createElement("INPUT");
        buton.type = "button";
        buton.value = "Enviar";
        node.appendChild(buton);
        
        parent.appendChild(node);
        
        var photo = parent.parentElement.id;
        var photoSplit = photo.split("foto")
        
        buton.onclick = function nuevoComent()
        {
            
            var texto = input.value;
            var idUser = user.id;
            var idPhoto = photoSplit[1];
            
            var nuevoComentario = {action:"nuevoComentario",texto:texto, idUser:idUser, idPhoto:parseInt(idPhoto)};
            socket.send(JSON.stringify(nuevoComentario));
            
            var listaComentarios = {action:"listaComentarios", idPhoto:parseInt(idPhoto)};
            socket.send(JSON.stringify(listaComentarios));
            
        }
    }
    
}

function salir()
{

            document.getElementById("sectionLogin").style.display="block";
            document.getElementsByClassName("best")[0].style.display="none";
            document.getElementById("indexfot").style.display="none";
            document.getElementById("buscar").style.display="none";
            document.getElementById("salir").style.display="none"; 
    
}

















