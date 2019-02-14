// Create table header
function createTableHeader(tableID, workout) {
    var header = document.createElement('thead');
    var headerInfo = workout.header;               
    for(var i = 0, length = headerInfo.length; i < length; i++) {
        var column = document.createElement('td');
        column.innerHTML = headerInfo[i];
        if(i == 0) column.style.width = 15 + '%';
        else       column.style.width = 5  + '%';
        header.appendChild(column);
    }
    var endColumn = document.createElement('td');
    endColumn.innerHTML = 'Progress';
    endColumn.style.textAlign = 'center';
    header.appendChild(endColumn);
    return header;
}

// Create a row element from information
function createTableBody(tableID, workout) {
    var body = document.createElement('tbody');                 
    for(var i = 0; i < workout.body.length; i++) {
        var row = createTableRow(tableID, workout, i);
        body.appendChild(row);
    }
    return body;
}

// Create row for the body of a table
function createTableRow(tableID, workout, rowID) {
    var row = document.createElement('tr');     // Create row element
    var headerInfo = workout.header;            // Use header as reference for body
    var bodyInfo   = workout.body;
    var setID = tableID + '-row-sets-' + rowID;
    // Create column elements using header
    for(var i = 0, length = headerInfo.length; i < length; i++) {    
        var column = document.createElement('td');
        var stringKey = headerInfo[i];
        column.innerHTML = bodyInfo[rowID][stringKey];
        // If "Sets" column set properties accordingly
        if(stringKey == 'Sets') {
            column.id = setID;
            column.completedSets = 0;
            column.totalSets = column.innerHTML;
            column.innerHTML = column.completedSets + '/' + column.totalSets;
        }
        row.appendChild(column);
    }
    // Create progress bar
    var buttonID = tableID + '-row-button-' + rowID;    
    var barID    = tableID + '-row-bar-'    + rowID;
    var rest     = bodyInfo[rowID].Rest * 1000;         // Milliseconds
    var countdown = createTableCountdown(buttonID, barID, rest, setID);
    row.appendChild(countdown);
    return row;
}

// Create countdown class that also updates the total of completed sets
function createTableCountdown(buttonID, barID, rest, setID) {
    var column = document.createElement('td');
    var countdown = createCountdown(buttonID, barID, rest);
    var button = countdown.children[0];
    button.innerHTML = 'Start';
    button.setID = setID;
    var startTimer    = 'startTimer(this.id, this.barID, this.duration);';
    var updateRowSets = 'updateRowSets(this.setID);';
    button.setAttribute('onclick', startTimer + updateRowSets);
    column.appendChild(countdown);
    return column;
}

// Increment number of sets completed
function updateRowSets(setID) {
    var column = document.getElementById(setID);
    column.completedSets++;
    column.innerHTML = column.completedSets + '/' + column.totalSets;
}

// Create table from row elements
function createTable(tableID, workout) {
    var table = document.getElementById(tableID);               // Get table
    var header = createTableHeader(tableID, workout);
    var body = createTableBody(tableID, workout);
    table.appendChild(header);                                  // Append to table
    table.appendChild(body);
}

var workout = {
    "header": ['Name', 'Reps', 'Sets', 'Rest'],
    "body":[
        {
            'Name': 'Dumbbell Pushup',
            'Reps': 12,
            'Sets': 3,
            'Rest': 60
        },
        {
            'Name': 'Pectorial Lift',
            'Reps': 12,
            'Sets': 3,
            'Rest': 60
        },
        {
            'Name': 'Bicep Curl',
            'Reps': 12,
            'Sets': 3,
            'Rest': 60
        },
        {
            'Name': 'Situps',
            'Reps': 12,
            'Sets': 3,
            'Rest': 60
        },
        {
            'Name': 'Plank',
            'Reps': 12,
            'Sets': 3,
            'Rest': 60
        },
        {
            'Name': 'Leg Lift',
            'Reps': 12,
            'Sets': 3,
            'Rest': 60
        }
    ]
}
