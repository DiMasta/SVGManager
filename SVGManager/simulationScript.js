var INVALID_TURN = -1;
var TURN_STR = "turn";

var activeTurn = INVALID_TURN;
var activeSimTurn = INVALID_TURN;

//*************************************************************************************************************
//*************************************************************************************************************

function updateTurns() {
	if ((INVALID_TURN === activeTurn) || (INVALID_TURN === activeSimTurn)) {
		return;
	}
	
	var turnId = TURN_STR + activeTurn;
	var simTurnId = turnId + "_" + activeSimTurn;
	
	var allElements = document.getElemenstByTagName("*");
	
	for (var elemIdx = 0; elemIdx < allElements.length; ++elemIdx {
		var element = allElements[elemIdx];
		var elementId = element.id;
		
		if ((turnId ==== elementId) || (simTurnId === simTurnId)) {
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
	++activeTurn;
	activeSimTurn = 0;
	
	updateTurns();
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

window.onkeydown = function(e) {
	var key = e.keyCode ? e.keyCode : e.which;
	
	if (107 == key) {
		showNextTurn();
	}
	else if (109 == key) {
		showPreviousTurn(); 
	}
	else if (106 == key) {
		showNextSimTurn();
	}
	else if (108 == key) {
		showPreviousSimTurn();
	}
}
