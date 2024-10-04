const Parser = require('tree-sitter');
const Crochet = require('./../Parser/tree-sitter-CrochetLan/node_modules/.bin/build/Release/tree_sitter_CrochetLan_binding.node'); // Adjust path as needed

const parser = new Parser();
parser.setLanguage(Crochet);

const sourceCode = `
ch ch ch ch
sc @ [0, 1]
`;

const tree = parser.parse(sourceCode);

const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 8080 });

wss.on('connection', ws => {
    ws.on('message', message => {
        // console.log(`Received movement type: ${message}`);
        // Pass the movement type to the parser
        parse_movement(message);
    });
});

function parse_movement(movementType) {
    // This is where you'd use Tree-Sitter to build a net structure
    console.log(`Parsing data: ${movementType}`);
    const curr_stitch = parser.parse(String(movementType));
    const connections = {curr_stitch};  // Example net structure
    // Create JSON structure
    const json = JSON.stringify(connections);
    console.log(json);
    // Write JSON to a file
    const fs = require('fs');
    fs.writeFileSync('output.json', json);
}
