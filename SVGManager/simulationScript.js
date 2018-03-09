var INVALID_TURN = -1;
var TURN_STR = "turn";

var SPACE_KEY = 32;
var Q_KEY = 81;
var W_KEY = 87;
var A_KEY = 65;
var S_KEY = 83;

var activeTurn = INVALID_TURN;
var activeSimTurn = INVALID_TURN;
var simTurnsCount = 0;

//*************************************************************************************************************
//*************************************************************************************************************

function updateTurns() {
	if ((INVALID_TURN === activeTurn) || (INVALID_TURN === activeSimTurn)) {
		return;
	}
	
	document.getElementById("infoText").textContent = "Turn= " + activeTurn + " SimTurn=" + activeSimTurn;
	
	var turnId = TURN_STR + activeTurn;
	var simTurnId = turnId + "_" + activeSimTurn;
	
	var allElements = document.getElementsByTagName("g");
	
	for (var elemIdx = 0; elemIdx < allElements.length; ++elemIdx) {
		var element = allElements[elemIdx];
		var elementId = element.id;
		
		if (turnId === elementId) {
			element.style.display = "block";
		}
		else if  (simTurnId === elementId) {
			element.style.display = "block";
		}
		else {
			element.style.display = "none";
		}
	}
}

//*************************************************************************************************************
//*************************************************************************************************************

function showNextTurn() {
	var turnsCount = document.getElementById("turnsCount").getAttribute("data-turns");
	if (activeTurn < turnsCount - 1) {	
		++activeTurn;
		activeSimTurn = 0;
		
		updateTurns();
	}
	else {
		alert("NO NEXT TURNS TO SHOW");
	}
}

//*************************************************************************************************************
//*************************************************************************************************************

function showPreviousTurn() {
	if (activeTurn <= 0) {
		alert("NO PREVOIS TURNS TO SHOW");
		return;
	}
	else {
		--activeTurn;
		activeSimTurn = 0;
	}
	
	updateTurns();
}

//*************************************************************************************************************
//*************************************************************************************************************

function showNextSimTurn() {
	++activeSimTurn;
	updateTurns();
}

//*************************************************************************************************************
//*************************************************************************************************************

function showPreviousSimTurn() {
	if (activeSimTurn <= 0) {
		alert("NO PREVOIS SIM TURNS TO SHOW");
		return;
	}
	else {
		--activeSimTurn;
		updateTurns();
	}
}

//*************************************************************************************************************
//*************************************************************************************************************

function constructHelpKeyStr(keyInt, keyFunc) {
	return String.fromCharCode(keyInt) + ": " + keyFunc;
}

//*************************************************************************************************************
//*************************************************************************************************************

function showHelp() {
	var helpStr = "Keys:\n\n";
	helpStr += "SPACE: \tShows help.";
	helpStr += "\n";
	helpStr += constructHelpKeyStr(Q_KEY, "Previous turn");
	helpStr += "\n";
	helpStr += constructHelpKeyStr(W_KEY, "Next turn");
	helpStr += "\n";
	helpStr += constructHelpKeyStr(A_KEY, "Previous simulated turn");
	helpStr += "\n";
	helpStr += constructHelpKeyStr(S_KEY, "Next simulated turn");
	
	alert(helpStr);
}

//*************************************************************************************************************
//*************************************************************************************************************

window.onkeydown = function(e) {
	var key = e.keyCode ? e.keyCode : e.which;
	
	if (SPACE_KEY == key) {
		showHelp();
	}
	else if (W_KEY == key) {
		showNextTurn();
	}
	else if (Q_KEY == key) {
		showPreviousTurn(); 
	}
	else if (S_KEY == key) {
		showNextSimTurn();
	}
	else if (A_KEY == key) {
		showPreviousSimTurn();
	}
}
