var WorkoutTable = new(function() {
    var tables = [];

    function init() {
        $("table.workout-table").each((index, workout_table) => {
            var table = new WorkoutTable(workout_table);
            tables.push(table);
        });
    }

    class WorkoutTable {
        constructor(table_selector) {
            this.table = $(table_selector);
            this.url = this.table.attr("url");
            this.exerciseTemplate = $("template#workout_table_exercise").html();
            this.load();
        }

        load() {
            var response = $.getJSON(this.url);
            response.done(this.url, data => {
                this.createTable(data);
                ModalForm.bind_buttons();
                ModalConfirm.bind_buttons();
            });
            response.fail(error => {
                flash_message(this.table, error.responseJSON.text, "danger");
            });
        }

        createTable(data) {
            var data = this.formatData(data);
            var columns = this.getColumns();
            // Doesnt work with jquery or javascript DOM objects
            // this.table.DataTable({
            //     'data': data,
            //     'border-collapse': 'collapse',
            //     'responsive': true,
            //     'autowidth': false,
            //     'columns': columns
            // });
            var header = $("<thead></thead>");
            columns.forEach(column => {
                header.append("<th style='width: {0};'>{1}</th>".format(column.width, column.title));
            });
            var body = $("<tbody></tbody>");
            data.forEach(rowData => {
                var row = $("<tr></tr>");
                rowData.forEach(columnData => {
                    var column = $("<td></td>");
                    column.append(columnData);
                    row.append(column);
                });
                body.append(row);
            });
            this.table.append(header);
            this.table.append(body);
        }

        getColumns() {
            var columns = [
                {'title': 'Name', 'width': '15%'},
                {'title': 'Reps', 'width': '5%'},
                {'title': 'Sets', 'width': '5%'},
                {'title': 'Rest', 'width': '5%'},
                {'title': 'Progress', 'width': 'auto'}
            ];
            return columns;
        }

        formatData(data) {
            var table = [];
            data.exercises.forEach(exercise => {
                table.push(this.formatExercise(exercise));
            });
            return table;
        }

        formatExercise(exercise) {
            var row = [];
            var progressBar = this.createProgressBar(exercise);
            row.push(this.formatExerciseName(exercise));
            row.push(exercise.reps);
            row.push(progressBar.sets);
            row.push("<div title='{0} seconds'>{0}</div>".format(exercise.rest));
            row.push(progressBar.bar);
            return row;
        }

        formatExerciseName(exercise) {
            var wrapper = $(this.exerciseTemplate).clone();
            wrapper.find("[name='name']").html(exercise.name);
            if(exercise.description) {
                wrapper.find("div.description").attr("title", exercise.description);
            }
            var args = {"exercise_id": exercise.id};
            // insert modify button urls
            var modify_button = wrapper.find("button[name='modify_button']");
            modify_button.attr({
                "get-url": Flask.url_for("workout.get_exercise", args),
                "post-url": Flask.url_for("workout.modify_exercise", args)
            })
            // insert remove button url
            var remove_button = wrapper.find("button[name='remove_button']");
            remove_button.attr("url", Flask.url_for("workout.remove_exercise", args));
            return $(wrapper)[0].outerHTML;
        }

        // returns a 
        createProgressBar(exercise) {
            var bar = new ProgressBar(exercise.rest);
            var sets = $("<a>0/{0}</a>".format(exercise.sets)).attr("value", 0);
            bar.click(() => {
                var newValue = parseInt(sets.attr("value")) + 1;
                sets.attr("value", newValue);
                sets.html("{0}/{1}".format(newValue, exercise.sets));
            });
            return {
                "bar": bar.background, 
                "sets": sets
            };
        }
    };

    return {
        "init": init,
        "tables": tables,
        "WorkoutTable": WorkoutTable
    };
});