/*
	Copyright (C) 2003-2006 Cies Breijs <cies AT kde DOT nl>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public
	License along with this program; if not, write to the Free
	Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
	Boston, MA 02110-1301, USA.
*/

#ifndef _PARSER_H_
#define _PARSER_H_



#include "errormsg.h"
#include "tokenizer.h"
#include "treenode.h"


/**
 * @short Uses a Tokenizer to step-wise parse KTurtle code to a node tree.
 *
 * The Parser uses a Tokenizer to read the KTurtle code as tokens.
 * It step-by-step parses the tokens to a node tree.
 * When errors occur they are added to the error list.
 *
 * A large part of the code of this class is generated code.
 *
 * @author Cies Breijs
 */
class Parser
{
	public:
		/**
		 * @short Constructor. Initialses the Parser.
		 * does nothing special. @see initialize().
		 */
		Parser(bool testing = false) : m_testing(testing) {}

		/**
		 * @short Destructor. Does nothing special.
		 */
		~Parser() {}


		/**
		 * @short Initializes (resets) the Parser
		 * Use this method to reset the Parser.
		 *
		 * It creates the 'root' node, and gets the first token.
		 * @param tokenizer pointer to a Tokenizer
		 * @param errorList pointer to a QList for ErrorMessage objects, when
		 *                  error occur they will be stored here
		 */
		void initialize(Tokenizer* _tokenizer, ErrorList* _errorList);

		/**
		 * @short Parses one 'step' (usually one statement).
		 * It calls @ref parseStatement() to receive a little piece of tree (some nodes)
		 * and appends them to the current scope.
		 *
		 * When it detects an EndOfInput token it sets finished to TRUE and stops
		 * working. @see isFinished
		 */
		void         parse();

		/**
		 * @short Reflects if the Parser has finished parsing (got an EndOfInput token).
		 * @return TRUE when parsing has finished otherwise FALSE.
		 */
		bool         isFinished() const { return finished; }

		/**
		 * @short Method to get the root node of the node tree (pointer based data stucture).
		 * The Parser does not delete the node tree so this pointer can be passed
		 * to the Executer.
		 * @returns The pointer to the root node.
		 */
		TreeNode*    getRootNode() const    { return rootNode; }

		void         printTree() const;

	private:
		void         nextToken();
		bool         skipToken(int expectedTokenType);
		bool         skipToken(int expectedTokenType, Token& byToken);
		void         addError(const QString& s, const Token& t, int code);
		void         appendArguments(TreeNode* node);

		TreeNode*    parseStatement();
		TreeNode*    parseFactor();
		TreeNode*    parseSignedFactor();
		TreeNode*    parseTerm();
		TreeNode*    parseExpression();

		Tokenizer   *tokenizer;
		ErrorList   *errorList;

		TreeNode    *rootNode;
		TreeNode    *currentScope;
		TreeNode    *newScope;
		Token       *currentToken;
		bool         finished;

		bool         m_testing;


// Next you find individual parse functions as generated:

//BEGIN GENERATED parser_h CODE

/* The code between the line that start with "//BEGIN GENERATED" and "//END GENERATED"
 * is generated by "generate.rb" according to the definitions specified in
 * "definitions.rb". Please make all changes in the "definitions.rb" file, since all
 * all change you make here will be overwritten the next time "generate.rb" is run.
 * Thanks for looking at the code!
 */

		TreeNode* parseUnknown();
		TreeNode* parseVariable();
		TreeNode* parseFunctionCall();
		TreeNode* parseScopeOpen();
		TreeNode* parseScopeClose();
		TreeNode* parseExit();
		TreeNode* parseIf();
		TreeNode* parseElse();
		TreeNode* parseRepeat();
		TreeNode* parseWhile();
		TreeNode* parseFor();
		TreeNode* parseBreak();
		TreeNode* parseReturn();
		TreeNode* parseWait();
		TreeNode* parseLearn();
		TreeNode* parseReset();
		TreeNode* parseClear();
		TreeNode* parseCenter();
		TreeNode* parseGo();
		TreeNode* parseGoX();
		TreeNode* parseGoY();
		TreeNode* parseForward();
		TreeNode* parseBackward();
		TreeNode* parseDirection();
		TreeNode* parseTurnLeft();
		TreeNode* parseTurnRight();
		TreeNode* parsePenWidth();
		TreeNode* parsePenUp();
		TreeNode* parsePenDown();
		TreeNode* parsePenColor();
		TreeNode* parseCanvasColor();
		TreeNode* parseCanvasSize();
		TreeNode* parseSpriteShow();
		TreeNode* parseSpriteHide();
		TreeNode* parsePrint();
		TreeNode* parseFontSize();
		TreeNode* parseRandom();
		TreeNode* parseGetX();
		TreeNode* parseGetY();
		TreeNode* parseMessage();
		TreeNode* parseAsk();
		TreeNode* parsePi();
		TreeNode* parseTan();
		TreeNode* parseSin();
		TreeNode* parseCos();
		TreeNode* parseArcTan();
		TreeNode* parseArcSin();
		TreeNode* parseArcCos();
		TreeNode* parseSqrt();
		TreeNode* parseExp();
		TreeNode* parseRound();

//END GENERATED parser_h CODE

};


#endif // _TOKENIZER_H_
