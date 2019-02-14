// Create table header
function createTableHeader(workouts) {
    var header = document.createElement('thead');
    var headerInfo = workouts.header;               
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
function createTableBody(workouts) {
    var body = document.createElement('tbody');                 
    for(var i = 0; i < workouts.body.length; i++) {
        var row = createTableRow(workouts.header, workouts.body[i]);
        body.appendChild(row);
    }
    return body;
}

// Create row for the body of a table
function createTableRow(header, workout) {
    var row = document.createElement('tr');
    var setsCol = undefined;    
    // Normal columns 
    for(var i = 0, length = header.length; i < length; i++) {    
        var column = document.createElement('td');
        var key = header[i];
        column.innerHTML = workout[key];
        if(key == 'Sets') {
            column.completedSets = 0;
            column.totalSets = column.innerHTML;
            column.innerHTML = column.completedSets + '/' + column.totalSets;
            setsCol = column;
        }
        row.appendChild(column);
    }
    // Create progress bar
    var rest = workout.Rest * 1000;         // Milliseconds
    var countdown = createTableCountdown(setsCol, rest);
    row.appendChild(countdown);
    return row;
}

// Create countdown class that also updates the total of completed sets
function createTableCountdown(setsCol, rest) {
    var column = document.createElement('td');
    var countdown = createCountdown(rest);
    var button = countdown.children[0];
    button.innerHTML = 'Start';
    button.setsCol = setsCol;
    var startTimer    = 'startTimer(this, this.bar, this.duration);';
    var updateRowSets = 'updateRowSets(this.setsCol);';
    button.setAttribute('onclick', startTimer + updateRowSets);
    column.appendChild(countdown);
    return column;
}

// Increment number of sets completed
function updateRowSets(column) {
    column.completedSets++;
    column.innerHTML = column.completedSets + '/' + column.totalSets;
}

// Create table from row elements
function createTable(tableID, workouts) {
    var table = document.getElementById(tableID);               // Get table
    var header = createTableHeader(workouts);
    var body = createTableBody(workouts);
    table.appendChild(header);                                  // Append to table
    table.appendChild(body);
}

var workouts = {
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
