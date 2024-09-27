#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 28
#define LARGE_STATE_COUNT 3
#define SYMBOL_COUNT 22
#define ALIAS_COUNT 0
#define TOKEN_COUNT 15
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_ch = 1,
  anon_sym_sc = 2,
  anon_sym_hdc = 3,
  anon_sym_dc = 4,
  anon_sym_tc = 5,
  anon_sym_AT = 6,
  anon_sym_LBRACK = 7,
  anon_sym_COMMA = 8,
  anon_sym_RBRACK = 9,
  aux_sym_stitch_count_token1 = 10,
  anon_sym_repeat = 11,
  anon_sym_times = 12,
  anon_sym_LBRACE = 13,
  anon_sym_RBRACE = 14,
  sym_source_file = 15,
  sym__statement = 16,
  sym_stitch = 17,
  sym_stitch_count = 18,
  sym_coordinate = 19,
  sym_loop = 20,
  aux_sym_source_file_repeat1 = 21,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_ch] = "ch",
  [anon_sym_sc] = "sc",
  [anon_sym_hdc] = "hdc",
  [anon_sym_dc] = "dc",
  [anon_sym_tc] = "tc",
  [anon_sym_AT] = "@",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [aux_sym_stitch_count_token1] = "stitch_count_token1",
  [anon_sym_repeat] = "repeat",
  [anon_sym_times] = "times",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym_stitch] = "stitch",
  [sym_stitch_count] = "stitch_count",
  [sym_coordinate] = "coordinate",
  [sym_loop] = "loop",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_ch] = anon_sym_ch,
  [anon_sym_sc] = anon_sym_sc,
  [anon_sym_hdc] = anon_sym_hdc,
  [anon_sym_dc] = anon_sym_dc,
  [anon_sym_tc] = anon_sym_tc,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [aux_sym_stitch_count_token1] = aux_sym_stitch_count_token1,
  [anon_sym_repeat] = anon_sym_repeat,
  [anon_sym_times] = anon_sym_times,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym_stitch] = sym_stitch,
  [sym_stitch_count] = sym_stitch_count,
  [sym_coordinate] = sym_coordinate,
  [sym_loop] = sym_loop,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_ch] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sc] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_hdc] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_dc] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_tc] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_stitch_count_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_repeat] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_times] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_stitch] = {
    .visible = true,
    .named = true,
  },
  [sym_stitch_count] = {
    .visible = true,
    .named = true,
  },
  [sym_coordinate] = {
    .visible = true,
    .named = true,
  },
  [sym_loop] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(15);
      ADVANCE_MAP(
        ',', 23,
        '@', 21,
        '[', 22,
        ']', 24,
        'c', 10,
        'd', 2,
        'h', 6,
        'r', 7,
        's', 3,
        't', 4,
        '{', 28,
        '}', 29,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(25);
      END_STATE();
    case 1:
      if (lookahead == 'a') ADVANCE(14);
      END_STATE();
    case 2:
      if (lookahead == 'c') ADVANCE(19);
      END_STATE();
    case 3:
      if (lookahead == 'c') ADVANCE(17);
      END_STATE();
    case 4:
      if (lookahead == 'c') ADVANCE(20);
      if (lookahead == 'i') ADVANCE(11);
      END_STATE();
    case 5:
      if (lookahead == 'c') ADVANCE(18);
      END_STATE();
    case 6:
      if (lookahead == 'd') ADVANCE(5);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(1);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(13);
      END_STATE();
    case 10:
      if (lookahead == 'h') ADVANCE(16);
      END_STATE();
    case 11:
      if (lookahead == 'm') ADVANCE(9);
      END_STATE();
    case 12:
      if (lookahead == 'p') ADVANCE(8);
      END_STATE();
    case 13:
      if (lookahead == 's') ADVANCE(27);
      END_STATE();
    case 14:
      if (lookahead == 't') ADVANCE(26);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_ch);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_sc);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_hdc);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_dc);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_tc);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_stitch_count_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(25);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_repeat);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_times);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_ch] = ACTIONS(1),
    [anon_sym_sc] = ACTIONS(1),
    [anon_sym_hdc] = ACTIONS(1),
    [anon_sym_dc] = ACTIONS(1),
    [anon_sym_tc] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [aux_sym_stitch_count_token1] = ACTIONS(1),
    [anon_sym_repeat] = ACTIONS(1),
    [anon_sym_times] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(25),
    [sym__statement] = STATE(6),
    [sym_stitch] = STATE(6),
    [sym_loop] = STATE(6),
    [aux_sym_source_file_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_ch] = ACTIONS(5),
    [anon_sym_sc] = ACTIONS(5),
    [anon_sym_hdc] = ACTIONS(5),
    [anon_sym_dc] = ACTIONS(5),
    [anon_sym_tc] = ACTIONS(5),
    [anon_sym_repeat] = ACTIONS(7),
  },
  [2] = {
    [sym__statement] = STATE(2),
    [sym_stitch] = STATE(2),
    [sym_loop] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(9),
    [anon_sym_ch] = ACTIONS(11),
    [anon_sym_sc] = ACTIONS(11),
    [anon_sym_hdc] = ACTIONS(11),
    [anon_sym_dc] = ACTIONS(11),
    [anon_sym_tc] = ACTIONS(11),
    [anon_sym_repeat] = ACTIONS(14),
    [anon_sym_RBRACE] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(19), 1,
      anon_sym_AT,
    ACTIONS(21), 1,
      aux_sym_stitch_count_token1,
    STATE(8), 1,
      sym_stitch_count,
    ACTIONS(17), 8,
      ts_builtin_sym_end,
      anon_sym_ch,
      anon_sym_sc,
      anon_sym_hdc,
      anon_sym_dc,
      anon_sym_tc,
      anon_sym_repeat,
      anon_sym_RBRACE,
  [20] = 4,
    ACTIONS(7), 1,
      anon_sym_repeat,
    ACTIONS(23), 1,
      anon_sym_RBRACE,
    STATE(2), 4,
      sym__statement,
      sym_stitch,
      sym_loop,
      aux_sym_source_file_repeat1,
    ACTIONS(5), 5,
      anon_sym_ch,
      anon_sym_sc,
      anon_sym_hdc,
      anon_sym_dc,
      anon_sym_tc,
  [40] = 4,
    ACTIONS(7), 1,
      anon_sym_repeat,
    ACTIONS(25), 1,
      anon_sym_RBRACE,
    STATE(4), 4,
      sym__statement,
      sym_stitch,
      sym_loop,
      aux_sym_source_file_repeat1,
    ACTIONS(5), 5,
      anon_sym_ch,
      anon_sym_sc,
      anon_sym_hdc,
      anon_sym_dc,
      anon_sym_tc,
  [60] = 4,
    ACTIONS(7), 1,
      anon_sym_repeat,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    STATE(2), 4,
      sym__statement,
      sym_stitch,
      sym_loop,
      aux_sym_source_file_repeat1,
    ACTIONS(5), 5,
      anon_sym_ch,
      anon_sym_sc,
      anon_sym_hdc,
      anon_sym_dc,
      anon_sym_tc,
  [80] = 1,
    ACTIONS(29), 10,
      ts_builtin_sym_end,
      anon_sym_ch,
      anon_sym_sc,
      anon_sym_hdc,
      anon_sym_dc,
      anon_sym_tc,
      anon_sym_AT,
      anon_sym_repeat,
      anon_sym_times,
      anon_sym_RBRACE,
  [93] = 2,
    ACTIONS(33), 1,
      anon_sym_AT,
    ACTIONS(31), 8,
      ts_builtin_sym_end,
      anon_sym_ch,
      anon_sym_sc,
      anon_sym_hdc,
      anon_sym_dc,
      anon_sym_tc,
      anon_sym_repeat,
      anon_sym_RBRACE,
  [107] = 1,
    ACTIONS(35), 8,
      ts_builtin_sym_end,
      anon_sym_ch,
      anon_sym_sc,
      anon_sym_hdc,
      anon_sym_dc,
      anon_sym_tc,
      anon_sym_repeat,
      anon_sym_RBRACE,
  [118] = 1,
    ACTIONS(37), 8,
      ts_builtin_sym_end,
      anon_sym_ch,
      anon_sym_sc,
      anon_sym_hdc,
      anon_sym_dc,
      anon_sym_tc,
      anon_sym_repeat,
      anon_sym_RBRACE,
  [129] = 1,
    ACTIONS(39), 8,
      ts_builtin_sym_end,
      anon_sym_ch,
      anon_sym_sc,
      anon_sym_hdc,
      anon_sym_dc,
      anon_sym_tc,
      anon_sym_repeat,
      anon_sym_RBRACE,
  [140] = 1,
    ACTIONS(41), 8,
      ts_builtin_sym_end,
      anon_sym_ch,
      anon_sym_sc,
      anon_sym_hdc,
      anon_sym_dc,
      anon_sym_tc,
      anon_sym_repeat,
      anon_sym_RBRACE,
  [151] = 2,
    ACTIONS(43), 1,
      aux_sym_stitch_count_token1,
    STATE(23), 1,
      sym_coordinate,
  [158] = 1,
    ACTIONS(45), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [163] = 2,
    ACTIONS(43), 1,
      aux_sym_stitch_count_token1,
    STATE(24), 1,
      sym_coordinate,
  [170] = 2,
    ACTIONS(21), 1,
      aux_sym_stitch_count_token1,
    STATE(20), 1,
      sym_stitch_count,
  [177] = 2,
    ACTIONS(43), 1,
      aux_sym_stitch_count_token1,
    STATE(26), 1,
      sym_coordinate,
  [184] = 2,
    ACTIONS(43), 1,
      aux_sym_stitch_count_token1,
    STATE(27), 1,
      sym_coordinate,
  [191] = 1,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
  [195] = 1,
    ACTIONS(49), 1,
      anon_sym_times,
  [199] = 1,
    ACTIONS(51), 1,
      anon_sym_LBRACK,
  [203] = 1,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
  [207] = 1,
    ACTIONS(55), 1,
      anon_sym_COMMA,
  [211] = 1,
    ACTIONS(57), 1,
      anon_sym_COMMA,
  [215] = 1,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
  [219] = 1,
    ACTIONS(61), 1,
      anon_sym_RBRACK,
  [223] = 1,
    ACTIONS(63), 1,
      anon_sym_RBRACK,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(3)] = 0,
  [SMALL_STATE(4)] = 20,
  [SMALL_STATE(5)] = 40,
  [SMALL_STATE(6)] = 60,
  [SMALL_STATE(7)] = 80,
  [SMALL_STATE(8)] = 93,
  [SMALL_STATE(9)] = 107,
  [SMALL_STATE(10)] = 118,
  [SMALL_STATE(11)] = 129,
  [SMALL_STATE(12)] = 140,
  [SMALL_STATE(13)] = 151,
  [SMALL_STATE(14)] = 158,
  [SMALL_STATE(15)] = 163,
  [SMALL_STATE(16)] = 170,
  [SMALL_STATE(17)] = 177,
  [SMALL_STATE(18)] = 184,
  [SMALL_STATE(19)] = 191,
  [SMALL_STATE(20)] = 195,
  [SMALL_STATE(21)] = 199,
  [SMALL_STATE(22)] = 203,
  [SMALL_STATE(23)] = 207,
  [SMALL_STATE(24)] = 211,
  [SMALL_STATE(25)] = 215,
  [SMALL_STATE(26)] = 219,
  [SMALL_STATE(27)] = 223,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [11] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [14] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stitch, 1, 0, 0),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stitch_count, 1, 0, 0),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stitch, 2, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_loop, 5, 0, 0),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_loop, 6, 0, 0),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stitch, 7, 0, 0),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stitch, 8, 0, 0),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_coordinate, 1, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [59] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_CrochetLan(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
