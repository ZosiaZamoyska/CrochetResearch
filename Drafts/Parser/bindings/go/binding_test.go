package tree_sitter_CrochetLan_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-CrochetLan"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_CrochetLan.Language())
	if language == nil {
		t.Errorf("Error loading CrochetLan grammar")
	}
}
