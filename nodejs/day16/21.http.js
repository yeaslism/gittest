/**
 * Created by KICT-17 on 2016-07-19.
 */

const http = require('http');
const util = require('util');
const os = require('os');
const UrlParser = require('url');

let http_server = http.createServer(
    (req,res)=> {

        console.log(req.url);

        let header = {
            'Access-Control-Allow_Origin': '*',
            'Access-Control-Allow-Methods': 'GET',
            'Access-Control-Max-Age': '1000'
        };
        header['Content-Type']='text/plain';
        res.writeHead(200,header);
        res.end("hello");
    }
);
http_server.listen(8080);