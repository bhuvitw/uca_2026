import * as http from "http"

const server = http.createServer((req, res) => {
    
    res.setHeader('Access-Control-Allow-Origin', '*'); // Or specify your frontend URL, e.g., 'http://localhost:3000'
    res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS');
    res.setHeader('Access-Control-Allow-Headers', 'Content-Type');

    if (req.url === "/users" && req.method === "GET") {

        res.writeHead(200, { 'Content-Type': 'application/json' });

        res.end(JSON.stringify([
            {
                "id": 1,
                "name": "Tom",
                "isActive": true,
            },
            {
                "id": 2,
                "name": "John",
                "isActive": false
            },
            {
                "id": 3,
                "name": "Jerry",
                "isActive": true
            },
            {
                "id": 4,
                "name": "Alice",
                "isActive": false
            },
            {
                "id": 5,
                "name": "Bob",
                "isActive": true
            }]
        ))
    } else {
        res.writeHead(200, { 'Content-Type': 'application/json' });

        res.end(JSON.stringify({
            "data": "Hello World",
        }));
    }
})


const hostname = "127.0.0.1";
const port = "5000"
server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
});