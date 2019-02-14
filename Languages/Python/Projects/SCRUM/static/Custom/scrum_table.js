var ScrumTable = new(function() {
    var tables = [];

    // load all tables
    function init() {
        var scrum_tables = $("table.scrum-table");
        scrum_tables.each((index, scrum_table) => {
            var table = new ScrumTable(scrum_table);
            tables.push(table);
        });
    }

    // Scrum table
    class ScrumTable {
        constructor(table_selector) {
            this.table = $(table_selector);
            this.url = this.table.attr("url");
            this.story_template = $("template#scrum_table_story").html();
            this.epic_template = $("template#scrum_table_epic").html();
            this.load();
        }
        
        load() {
            var response = $.getJSON(this.url);
            response.done(scrum => {
                this.create_table(scrum);
            });
            response.fail(error => {
                flash_message(this.table, error.responseJSON.text, "danger");
            });
        }

        create_table(scrum) {
            var columns = this.get_table_formatting(scrum);
            var data = this.get_table_data(scrum);
            this.table.DataTable({
                'data': data,
                'border-collapse': 'collapse',
                'responsive': true,
                'autowidth': false,
                'columns': columns,
                'rowsGroup': [0],
            });
        }

        get_table_formatting(scrum) {
            var categories = scrum.categories;
            var width = String(100/(categories.length+1))+'%';
            var columns = [{
                'title': 'Epics',
                'width': width,
            }];
            for(var index in categories) {
                columns.push({
                    'title': categories[index],
                    'width': width,
                });
            }
            return columns;
        }

        get_table_data(scrum) {
            var data = [];
            scrum.epics.forEach(epic => {
                // format epic
                if(epic.stories === undefined || epic.stories.length == 0) {
                    var row = [];
                    row.push(this.format_epic_entry(epic));
                    for(var index in scrum.categories) {
                        row.push('');
                    }
                    data.push(row);
                }
                // format story
                epic.stories.forEach(story => {
                    var row = [];
                    row.push(this.format_epic_entry(epic));
                    scrum.categories.forEach(category => {
                        if(category != story.category) {
                            row.push('');
                        } else {
                            row.push(this.format_story_entry(story));
                        } 
                    });
                    data.push(row);
                });
            });
            return data;
        }

        format_epic_entry(epic) {
            return this.format_template(this.epic_template, epic);
        }

        format_story_entry(story) {
            return this.format_template(this.story_template, story);
        }

        format_template(template, form) {
            var wrapper = $(template).clone();
            for(var key in form) {
                $(wrapper).find("[name='"+key+"']").html(form[key]);
            }
            return $(wrapper)[0].outerHTML;
        }
    }

    return {
        "init": init,
        "tables": tables
    };
});
