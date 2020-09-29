$(function(){
    $("#types_list").collapse('show');
});

$('div.display_type').click(function(){
    if( $(this).attr('id') == "disp_txt" ){
        $("#types_list").collapse('show');
    }
    else{
        $("#types_list").collapse('hide');
    }

    $('div.display_type').removeClass('active');
    $(this).addClass('active');
});

function deleteTask(taskId){
    var subject = '#tasks > .task#'+taskId;
    $(subject).remove();
    var taskCnt = parseInt($('#taskCnt').text()) - 1;
    $('#taskCnt').text(taskCnt);
}

$('#plusik').click(function(){
    var taskCnt = parseInt($('#taskCnt').text()) + 1;
    var taskId = parseInt($(this).attr('alt')) + 1;
    
    var new_task ='<div id="'+taskId+'" class="task">'
                +'<div class="positioning"><div class="up">^</div><div class="down">v</div></div>'
                +'<textarea></textarea>'
                +'<div class="minusik" onclick="deleteTask('+taskId+')">-</div> </div>';
    $('#tasks').append(new_task);
    $(this).attr('alt', taskId);
    $('#taskCnt').text(taskCnt);

    var elem = $('#tasks');
    elem.scrollTop = elem.scrollHeight;

});

function makeSumbutedView(status){
    $('.plan_view').text('');
    var msg = "Wystąpił problem, nie można dodać pliku";
    if (status = 1)
        msg = "Dodano pomyślnie";
    var msgdiv = '<div class="makestatus">' + msg + '</div>';
    var subnav = '<div class="subnav">'
        + '<a class="greenbutton item" href="makeplan.php">Następny</a>'
        + '<a class="greenbutton item" href="planviewer.php">Powrót</a>'
        + '</div>';

        $('.plan_view').append(msgdiv);
        $('.plan_view').append(subnav);

    return msgdiv;
}

$('#submit').click(function(){
    var tasksCount = parseInt($('#plusik').attr('alt'));
    var name=$('#name').val();
    var description = $('#description').val();
    
    var plan = new Object;
    var features = new Object;
    var display = $('.display_type.active').attr('alt');
    var states = $('#types_list > textarea').val().split(',');

    for( var i=0; i<states.length; i++ ){
        states[i] = states[i].trim();
    }

    features.open = $('#open').prop('checked');
    features.states = states;
    features.display = display;
    features.startdate=false;
    features.enddate=false;

    t0 = new Object;
    t0.next="t1";
    var tasksMap = [["t0", t0]];
    for(var i=1; i <= tasksCount; i++){
        var elem = '#'+i+'.task > textarea';
        if( $(elem).length ){
            if( $(elem).val() != "" ){
                var task = new Object;
                task.text = $(elem).val();
                if (tasksCount > i) task.next = "t"+(i+1);
                else task.next="t0";
                tasksMap.push( ["t"+i, task] );
            }
        }
    }
    _map = new Map(tasksMap);
    var tasks = Object.fromEntries(_map);
    
    plan.features=features;
    plan.tasks=tasks;

    var request = new Object;
    request.name = name;
    request.description = description;
    request.author= $('#usr').text().trim();
    request.plan = plan;
    console.log(JSON.stringify(request));
    $.post("newplan.php",
        JSON.stringify(request),
        function (data) {
            makeSumbutedView(data.status);
        }
    );

});
