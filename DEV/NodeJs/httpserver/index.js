const http = require('http');
const { type } = require('os');
const url = require('url');
const fs = require('fs');

// to create a web server
const server = http.createServer((req, res) => {
    // console.log(req.url);
    if(req.url === '/') {
        res.end('Hello from the server !');
    }
    else if(req.url ==='/contact') {
        res.end('Hello fro, contact page...');
    }
    else if(req.url == '/userApi') {
        fs.readFile('./userAPI/userApi.json','utf-8', (err, data) => {
            console.log(data);
            res.end(data);
        });
    }
    else {
        res.writeHead(404);
        res.end('404 Error: Page not found!');
    }
})

server.listen(3000, "127.0.0.1", () => {
    console.log("Listening to port 3000!");
});