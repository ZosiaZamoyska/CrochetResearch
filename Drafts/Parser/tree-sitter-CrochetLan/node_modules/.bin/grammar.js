module.exports = grammar({
  name: 'CrochetLan',

  rules: {
    source_file: $ => repeat($._statement),

    _statement: $ => choice(
      $.stitch,
      $.loop
    ),

    stitch: $ => seq(
      choice('ch', 'sc', 'hdc', 'dc', 'tc'),
      optional($.stitch_count),
      optional(seq(
        '@',
        '[',
        $.coordinate,
        ',',
        $.coordinate,
        ']'
      ))
    ),

    stitch_count: $ => /\d+/,

    coordinate: $ => /\d+/,

    loop: $ => seq(
      'repeat',
      $.stitch_count,
      'times',
      '{',
      repeat($._statement),
      '}'
    )
  }
});
