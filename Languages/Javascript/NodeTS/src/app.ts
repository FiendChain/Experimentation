import * as express from "express";
import * as bodyParser from "body-parser";
import { Request, Response } from "express";

export default class App {
    public app: express.Application;

    constructor() {
        this.app = express();
        this.config();
        this.routes();
    }

    private config(): void {
        this.app
            .use(bodyParser.json())
            .use(bodyParser.urlencoded({ 
                extended: false 
            }));
    }

    private routes(): void {
        const router = express.Router();

        router.get('*', (request: Request, response: Response) => {
            const url: string = request.url;
            const method: string = request.method;
            var details: string = `${method} ${url}`; 
            console.log(details);
            response
                .status(200)
                .send(details);
        })

        this.app.use('/', router)
    }
}