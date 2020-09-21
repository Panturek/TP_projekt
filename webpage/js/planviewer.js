
function arrayToList( arr, ordered=false ) {
    len = $(arr).length;
    var order = "ul"
    if (ordered) order = "ol"; 
    var list = '<' + order + '>';
    for (var i = 0; i < len ; i++) {
        list += '<li>'+ arr[i] +'</li>';
    }
    list += '</' + order + '>';
    return list;
}

function getUserProgress(user_id, plan_id) {
    var request = new Object();
    request.plan_id = plan_id;
    request.user_id = user_id;
    console.log('1');
    $.post("plandata.php",
        JSON.stringify( request ),
        function (data) {
            var append_to = '#' + user_id + ".progress > .plan_data";
            var height = makeHtmlExecutiveElements(data, append_to);
            $('#' + user_id + '.progress').height( height * 23);
        }, "json"
    );
    
    $.post("planstate.php",
        JSON.stringify(request),
        function (data) {
            console.log(data);
        }, "json"
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

function makeHtmlExecutiveElements( data, append_to= "#tasks" ) {
    var features = data['features'];
    var tasks = data['tasks'];
    var defStates = features['states'];
    var isOrdered = features['ordered'];
    var display = features['display'];
    var startdate = features['startdate'];
    var enddate = features['enddate'];
    var classes = [];
    classes.push("exec");

    if (isOrdered) classes.push("ordered");
    if (startdate) classes.push("startdate");
    if (enddate) classes.push("enddate");
    if (display)
        classes.push(display);
    else
        classes.push('text');
    
    $(append_to).text("");
    var statesList = arrayToList(defStates);
    var keys = Object.keys(tasks);
    var ordnung = [ "-" ];
    if (isOrdered) {
        for (var i = 0; i < keys.length; i++) {
            var next = tasks[keys[i]]['next'];
            if (next != "-1") {
                ordnung.push(next);
            }
        }
        keys = ordnung;
    }

    for (var i = 1; i < keys.length; i++) {
        task = tasks[keys[i]];
        var elem = '<div class="task ' + classes.join(" ")
            + '" id="' + keys[i] + '">'
            + '<div class="details">' + task['text'] + '</div>'
            + '<div class="state '+display+'">' + statesList + '</div>'
            + '<div class="startdate' + ( startdate? "": " hidden" ) + '">__DATE__</div>'
            + '<div class="enddate' + ( enddate? "": " hidden" ) + '">__DATE__</div>'
            + '</div>';
        $(elem).appendTo(append_to);
    };
    return ( keys.length - 1 );
}

function setExecutivesStatus(data) {
    $.each(data, function(key, value){
        var elem = '#' + key +'.task > .state';
        $(elem).append(data[key]['state']);
    });
}

function getExecuted(plan_id, user_id) {
    var request = new Object();
    request.plan_id = plan_id;
    request.user_id = user_id;

    $.post("plandata.php",
        JSON.stringify( request ),
        function (data) {
            makeHtmlExecutiveElements(data);
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
}