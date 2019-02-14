function ScoreBoard(elementID) {
    this.scoreboard = document.getElementById(elementID);
    this.initialised = false;
    this.score = {
        "left": 0,
        "right": 0,
    }
    this.scoreElems = {
        "left":  document.createElement("a"),
        "right": document.createElement("a"),
    };

    this.initialise = function() {
        var left = document.createElement("b");   // Left 
        left.innerHTML = "Left: ";
        var newline = document.createElement("br");
        var right = document.createElement("b");   // Right
        right.innerHTML = "Right: ";
        var elemArray = [
            left,  this.scoreElems.left, newline,
            right, this.scoreElems.right,
        ];
        for(var i = 0, length = elemArray.length; i < length; i++) {
            this.scoreboard.appendChild(elemArray[i]);
        }
        this.initialised = true;
        this.setScore();
    }

    this.setScore = function() {
        if(this.initialised == false) {
            this.initialise();
        }
        this.scoreElems.left.innerHTML = this.score.left;
        this.scoreElems.right.innerHTML = this.score.right;
    }

    this.setWinner = function(winner) {
        if(winner == "left") {
            this.score.left += 1;
            this.setScore();
        } else if(winner == "right") {
            this.score.right += 1;
            this.setScore();
        }
    }
}