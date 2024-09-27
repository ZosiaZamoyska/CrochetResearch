package tree_sitter_crochetresearch_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_crochetresearch "github.com/tree-sitter/tree-sitter-crochetresearch/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_crochetresearch.Language())
	if language == nil {
		t.Errorf("Error loading Crochetresearch grammar")
	}
}
