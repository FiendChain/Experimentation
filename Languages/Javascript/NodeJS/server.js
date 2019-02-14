var http = require('http');

function onRequest(request, response) {
    console.log(request.method, " ", request.url);
    var data = {};
    if (request.method == 'GET') {
        if (request.url == '/Workout/workouts') {
            data = workouts;
        }
        else {
            data = workoutById(0);
        }
    }
    else if (request.method == 'POST') {
        if (request.url == '/Workout/workouts') {
            console.log('got POST: ', request);
        }
    }
    finishedRequest(response);
    response.write(JSON.stringify(data));
    response.end();
}
var CORS = {
    "Content-Type": 'application/json',
    'Access-Control-Allow-Origin': '*',
    'Access-Control-Allow-Methods': 'GET,PUT,PATCH,POST,DELETE',
    'Access-Control-Allow-Headers': 'Content-Type'
};
var workouts = [
    {
        "id": 0,
        "name": "James Delos",
        "description": "Westworld",
        "exercises": [
            {
                "id": 0,
                "name": "Live",
                "description": null,
                "rest": 60,
                "sets": 3,
                "reps": 12
            },
            {
                "id": 1,
                "name": "Die",
                "description": null,
                "rest": 60,
                "sets": 3,
                "reps": 12
            },
            {
                "id": 2,
                "name": "Repeat",
                "description": null,
                "rest": 60,
                "sets": 3,
                "reps": 12
            },
        ]
    },
    {
        "id": 1,
        "name": "Who knows",
        "description": "Unknown bastard",
        "exercises": []
    },
];
function finishedRequest(response) {
    response.writeHead(200, CORS);
}
function workoutById(id) {
    id = Number(id);
    for (var _i = 0, workouts_1 = workouts; _i < workouts_1.length; _i++) {
        var workout = workouts_1[_i];
        if (workout.id == id)
            return workout;
    }
    return undefined;
}

http.createServer(onRequest)
    .listen(4001, "127.0.0.100")
