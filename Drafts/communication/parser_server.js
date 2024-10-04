const Parser = require('tree-sitter');
const Crochet = require('./../Parser/tree-sitter-CrochetLan/node_modules/.bin/build/Release/tree_sitter_CrochetLan_binding.node'); // Adjust path as needed

const parser = new Parser();
parser.setLanguage(Crochet);

const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 8080 });

wss.on('connection', ws => {
    ws.on('message', message => {
        // console.log(`Received movement type: ${message}`);
        parse_movement(message);
    });
});

function parse_movement(movementType) {
    console.log(`Parsing data: ${movementType}`);
    const curr_stitch = parser.parse(String(movementType));
    const connections = {curr_stitch}; 
    const json = JSON.stringify(connections);
    console.log(json);
    const fs = require('fs');
    fs.writeFileSync('output.json', json);
}
