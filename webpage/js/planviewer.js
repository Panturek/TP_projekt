function foldStates() { 
    $('.task > .state > ul').css('display', 'none');
    $('.task > .state > .curr').css('display', 'block');
}

function setNewState(plan_id, user_id, task_id, state ) {
    if (plan_id == 0)
        return;
    var request = new Object();
    request.plan_id = plan_id;
    request.user_id = user_id;
    request.task_id = task_id;
    request.state = state;
    $.post("setstate.php",
        JSON.stringify(request),
        function (data) {

        }, "json"
    );
    getExecuted(plan_id, user_id);
}

function arrayToList(arr, plan_id, user_id, id) {
    len = $(arr).length;
    
    var list = '<ul id="' + id + '" >';
    for (var i = 0; i < len; i++) {
        var li = '<li alt="' + plan_id + ',' + user_id + ',' + id + ','+ arr[i] + '">'
            + arr[i] + '</li>';
        list += li;
    }
    list += '</ul>';
    
    return list;
}

function setExecutivesStatus(data) {
    console.log(data);
    $.each(data, function (key, value) {
        var elem = '#' + key +'.task > .state';
        $(elem).append('<div class="curr">'+data[key]['state']+'</div>');
    });
}

function getUserProgress(user_id, plan_id) {
    var request = new Object();
    request.plan_id = plan_id;
    request.user_id = user_id;
    $.post("plandata.php",
        JSON.stringify(request),
        function (data) {
            var append_to = '#' + user_id + ".progress > .plan_data";
            var height = makeHtmlExecutiveElements(data, plan_id, user_id, append_to, true);
            $('#' + user_id + '.progress').height(height * 23);
        }, "json"
    );
    
    $.post("planstate.php",
        JSON.stringify(request),
        function(data){
            setExecutivesStatus(data);
        },"json"
    );
}

function makeHtmlReviewedElements(data) {
    $('#tasks').text("");
    var len = data.length - 1;
    for (var i = 0; i < len; i++) {
        var plan_id = data[len];
        var __data = data[i];
        var user_progress = '<div alt="' + plan_id + '" '
            + 'id = "' + __data[0] + '" '
            + 'class="progress" '
            + 'onclick="getUserProgress('+ __data[0] +', '+ plan_id +')" >'
            + '<div class="user">' + __data[1] + '</div>'
            + '<div class="plan_data"></div>'
            + '</div>';
        
        $('#tasks').append(user_progress);
    }
}

function changeState(plan_id, id) {
    foldStates();
    var item = '#' + id + '.task > .state ';
    $(item + ' > ul').css('display', 'block');
    $(item + ' > ul').attr('alt', plan_id + ' ' +id );
    $(item + '> .curr').css('display', 'none');
}

function makeHtmlExecutiveElements( data, plan_id, user_id=0, append_to= "#tasks", readOnly=false ) {
    var features = data['features'];
    var tasks = data['tasks'];
    var defStates = features['states'];
    var display = features['display'];
    var startdate = features['startdate'];
    var enddate = features['enddate'];
    var classes = [];
    
    if (!readOnly) classes.push("exec");
    else classes.push("view");
    if (startdate) classes.push("startdate");
    if (enddate) classes.push("enddate");
    if (display)
        classes.push(display);
    else
        classes.push('text');
    
    $(append_to).text("");
    var keys = Object.keys(tasks);
    var ordnung = ["-"];
    
    for (var i = 0; i < keys.length; i++) {
        var next = tasks[keys[i]]['next'];
            if (next != "t0") {
            ordnung.push(next);
            }
        }
    keys = ordnung;

    for (var i = 1; i < keys.length; i++) {
        var id = keys[i];
        var task = tasks[id];
        if (!task)
            continue;
        var statesList = arrayToList( defStates, plan_id, user_id, id );
        var elem = '<div class="task ' + classes.join(" ")
            + '" id="' + id + '">'
            + '<div class="details">' + task['text'] + '</div>'
            + '<div class="state ' + display + '" '
                + (readOnly? '': 'onclick="changeState(' + plan_id +', \''+ id + '\')' )
                + ' ">' + statesList + '</div>'
            + '<div class="startdate' + ( startdate? "": " hidden" ) + '">__DATE__</div>'
            + '<div class="enddate' + ( enddate? "": " hidden" ) + '">__DATE__</div>'
            + '</div>';
        $(elem).appendTo(append_to);
    };

    $('li').click(function () {
        var params = $(this).attr('alt').split(',');
        setNewState(params[0], params[1], params[2], params[3]);
    });

    var h = ( keys.length - 1 ) ;
    $('#tasks').height( h * 26 );
    return h;
}

function getExecuted(plan_id, user_id) {
    var request = new Object();
    request.plan_id = plan_id;
    request.user_id = user_id;

    $.post("plandata.php",
        JSON.stringify( request ),
        function (data) {
            makeHtmlExecutiveElements(data, plan_id, user_id);
        }, "json"
    );
    
    $.post("planstate.php",
        JSON.stringify( request ),
        function (data) {
            setExecutivesStatus(data);
        }, "json"
    );
}

function getReviewed(plan_id, user_id) {
    var request = new Object();
    request.plan_id = plan_id;
    request.user_id = user_id;

    $.post("planreview.php",
        JSON.stringify(request),
        function (data) {
            makeHtmlReviewedElements( data );
        }, "json"
    );
    return 1;
}

function addAsExecutive(plan_id, user_id) {
    var request = new Object();
    request.plan_id = plan_id;
    request.user_id = user_id;
    $.post("newexecutive.php",
        JSON.stringify(request),
        function (data) {
            //if (data.status) {
                console.log(data.status);
            //}
        });
}