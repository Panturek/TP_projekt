<?php
    session_start();

    if( (isset($_SESSION['zalogowany'])==false ) || ($_SESSION['zalogowany']==false)){
        header('Location: index.php');
        exit();
    }
    $_SESSION['pageid'] = 'nowe_plany';

?>

<!DOCTYPE HTML>
<html lang="pl">
<head>
    <meta charset="utf-8">
    
    <title>Projekt zaliczeniowy z przedmiotu aplikacje mobilne i internetowe </title>
    <meta name="description" content="Projekt zaliczeniowy">
    <meta name="keywords" content="projekt, zaliczenie, wykładu">
    <meta name="author" content="Jan Hałasiński">
    <meta http-equiv="X-Ua-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    
    <link rel="stylesheet" href="bootstrap/css/bootstrap.min.css">
    <link rel="stylesheet" href="css/main.css">
    <link rel="stylesheet" href="css/plans/default_light.css">

    <link rel="stylesheet" type="text/css" href="img/sliderstyle.css" />
    <link href="https://fonts.googleapis.com/css?family=Open+Sans:400,700&amp;subset=latin-ext" rel="stylesheet">

    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
    
    <script src="http://code.jquery.com/jquery-1.11.2.min.js"></script>

    <script src="bootstrap/js/bootstrap.min.js"></script>
    
    
    <script src="js/planviewer.js"></script>

</head>

<body>
<header>
    <?php
        include('./nav.php');
    ?>
</header>

<main>
    <div id="usr" class="hidden"><?php echo $_SESSION['id'];?></div>
    <div class="list_column">
        <div class="modes"> 
            <h3 class="mode active">Metadane Planu</h3>
        </div>

        <div class="meta_list"> 
            <h5> Nazwa: </h5>
                <input class="planfeat" type="text" name="name" id="name"> </input>
        
            <h5> Opis: </h5>
                <textarea class="planfeat" maxlength="400" id="description"> </textarea>
        
            <h5> Zapisz Kolejność: 
                <input type="checkbox" name="order" id="order"> </h5>
            
            <div>
                <h5> Wyświetlanie stanu: </h5>
                <div class="display_type active" id="disp_txt" alt="text" > tekstowy </div>
                    <div id="types_list" class="collapse">
                        <textarea class="display_type" placeholder="podaj stany po przecinku"></textarea>
                    </div>
                <div class="display_type" alt="checkbox" > odhaczenie </div>
            </div>
        </div>
    </div>

    <div class="plan_view">
        <h3 class="mode" style="float: left;">Zadania: <span id="taskCnt">0</span></h3>
        <div class="mode new" id="submit">Zatwierdź</div>
        <div style="clear:both;"></div>
        <div id="tasks">
        </div>
        <div style="clear:both"> </div>
        <div id="plusik" alt='0'> + <div>
    </div>

</main>

<footer>
    <?php include("./footer.php"); ?>
</footer>
<script>

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

        features.ordered = $('#order').prop('checked');
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

        $.post("newplan.php",
            JSON.stringify(request),
            function(data){
                console.log(data);
            }
        );

    });
    

</script>
</body>
</html>
