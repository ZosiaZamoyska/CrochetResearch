module.exports = grammar({
  name: 'crochet',

  rules: {
    source_file: $ => repeat($._statement),

    _statement: $ => choice(
      $.stitch,
      $.attached_stitch,
      $.loop
    ),

    stitch: $ => seq(
      choice('ch', 'sc', 'hdc', 'dc', 'tc'),
      optional($.stitch_count)
    ),

    attached_stitch: $ => seq(
      choice('sc', 'hdc', 'dc', 'tc'),
      '@',
      '[',
      $.coordinate,
      ',',
      $.coordinate,
      ']'
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
