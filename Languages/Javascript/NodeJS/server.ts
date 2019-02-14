import { ServerResponse } from "http";

var http: any = require('http');

interface Workout {
    id: number;
    name: string;
    description?: string;
    exercises: Exercise[];
}

interface Exercise {
    id: number;
    name: string;
    description?: string;
    reps: number;
    sets: number;
    rest: number;
}

function onRequest(request: Request, response: ServerResponse): void {
	console.log(request.method, " ", request.url);
	var data = {};
	if(request.method == 'GET') {
		if(request.url == '/Workout/workouts') {
			data = workouts;
		} else {
			data = workoutById(0);
		}
	} else if(request.method == 'POST') {
		if(request.url == '/Workout/workouts') {
			console.log('got POST: ', request);
		}
	}
	finishedRequest(response);
	response.write(JSON.stringify(data));
	response.end();
}

const CORS: any = {
	"Content-Type": 'application/json',
	'Access-Control-Allow-Origin': '*',
	'Access-Control-Allow-Methods': 'GET,PUT,PATCH,POST,DELETE',
	'Access-Control-Allow-Headers': 'Content-Type'
};

var workouts: Workout[] = [
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
				"reps": 12,
			},
			{
				"id": 1,
				"name": "Die",
				"description": null,
				"rest": 60,
				"sets": 3,
				"reps": 12,
			},
			{
				"id": 2,
				"name": "Repeat",
				"description": null,
				"rest": 60,
				"sets": 3,
				"reps": 12,
			},
		],
	},
	{
		"id": 1,
		"name": "Who knows",
		"description": "Unknown bastard",
		"exercises": [],
	},
];

function finishedRequest(response: ServerResponse) {
	response.writeHead(200, CORS);
}

function workoutById(id: number | string): Workout {
	id = Number(id);
	for(let workout of workouts) {
		if(workout.id == id) return workout;
	}
	return undefined;
}

http.createServer(onRequest)
	.listen(4000, "127.0.0.100");
