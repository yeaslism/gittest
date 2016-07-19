/**
 * Created by KICT-17 on 2016-07-19.
 */
const net = require('net');

const ip = '192.168.0.21';
const PORT = 8080;

let socket = new net.Socket();

socket.connect(PORT,ip,()=>{
    console.log('connect to : ' + ip + PORT);
    let req = {
        name : '빙고',
        value : 70
    }
    socket.write(JSON.stringify(req))
});

socket.on('data',(evt)=>{
    console.log(String(evt));
    //socket.end('bye~');
    socket.destroy();

});
socket.on('error',(evt)=>{

});
socket.on('close',()=>{

});