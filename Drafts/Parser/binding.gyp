{
  "targets": [
    {
      "target_name": "tree_sitter_CrochetLan_binding",
      "include_dirs": [
        "src",
        "node_modules/node-addon-api"
      ],
      "defines": [
        "NAPI_CPP_EXCEPTIONS"
      ],
      "sources": [
        "bindings/node/binding.cc",
        "src/parser.c",
        #"src/scanner.c",
        "grammar.js",
        "src/grammar.json",
        "src/node-types.json"
      ],
      "conditions": [
        ["OS!='win'", {
          "cflags_c": [
            "-std=c11"
          ]
        }, {
          "cflags_c": [
            "/std:c11",
            "/utf-8"
          ],
          "cflags": ["-std=c++11"],
          "cflags_cc": ["-std=c++11"]
        }]
      ]
    }
  ]
}
