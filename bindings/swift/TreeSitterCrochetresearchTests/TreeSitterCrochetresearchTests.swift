import XCTest
import SwiftTreeSitter
import TreeSitterCrochetresearch

final class TreeSitterCrochetresearchTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_crochetresearch())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Crochetresearch grammar")
    }
}
