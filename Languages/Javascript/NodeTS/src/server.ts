import * as express from "express";
import App from "./app";

var app: express.Application = new App().app;

const port: number = 4001;
const hostname: string = "127.0.0.100";

app.listen(port, hostname, () => {
    console.log(`Express server listening on ${hostname}:${port}`);
});