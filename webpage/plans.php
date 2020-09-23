<?php
    session_start();

    if( (isset($_SESSION['zalogowany'])==false ) || ($_SESSION['zalogowany']==false)){
        header('Location: index.php');
        exit();
    }
    $_SESSION['pageid'] = 'plany';
    
    include_once("config.php");
    $select_reviewed = "select reviewers.plan_id, plans.name
                        from tpprojekt.reviewers, tpprojekt.plans
                        where reviewers.plan_id like plans.plan_id
                        and user_id= ".$_SESSION['id'];
    $select_executed = "select executives.plan_id, plans.name
                        from tpprojekt.executives, tpprojekt.plans
                        where executives.plan_id like plans.plan_id
                        and user_id= ".$_SESSION['id'];

    $get_reviewed = mysqli_query($conn, $select_reviewed);
    $get_executed = mysqli_query($conn, $select_executed);

    if($get_reviewed){
        $reviewed_plans = mysqli_fetch_all($get_reviewed);
    }
    if($get_executed){
        $executed_plans = mysqli_fetch_all($get_executed);
    }
    
    @mysqli_close($conn);

    $rev_items='';
    if(isset($reviewed_plans)){
        foreach($reviewed_plans as $key=>$value){
            $rev_items=$rev_items.'<p class="plan_name review" id="'.$value[0].'" >'.$value[1].'</p>';
        }
    }
    $exec_items='';
    if(isset($executed_plans)){
        foreach($executed_plans as $key=>$value){
            $exec_items=$exec_items.'<p class="plan_name execute" id="'.$value[0].'">'.$value[1].'</p>';
        }
    }
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
    
    <script src="bootstrap/js/bootstrap.min.js"></script>
    
    <script src="http://code.jquery.com/jquery-1.11.2.min.js"></script>
    
    <script src="js/planviewer.js"></script>

</head>

<body>
<header>
    <?php
        include('./nav.php');
    ?>
</header>

<main>
    <div class="list_column">
        <div class="modes"> 
            <p class="mode card active" id="insp">Nadzorowane</p>
            <p class="mode card" id="exec">Wykonywane</p>
        </div>
        <div class="plans_list"> 
            <?php echo $rev_items; ?>
        </div>
        <div class="plans_list hidden">
            <?php echo $exec_items; ?>
        </div>
    </div>

    <div class="plan_view">
        <h3 class="mode" style="float: left;">Zadania:</h3> 
        <a class="mode new" href = "makeplan.php">Nowy</a>
        <div style="clear:both;"></div>
        <div id="tasks">
            <?php 
            //    include_once('planToHtml.php');
            //    getPlanData('plans/pattern.json');
            ?>
        </div>
    </div>

</main>

<footer>
    <?php include("./footer.php"); ?>
</footer>
<script>
    $.getJSON( "plans/pattern.json", function( data ) {
                makeHtmlExecutiveElements( data );
            }, "json"
        );

    $( "p.mode" ).click(function() {
        if( $(this).hasClass("active") ){
            return;
        }
        $( ".mode.card" ).toggleClass("active");
        $( ".plans_list" ).toggleClass("hidden");
    });

    $(".plan_name.review").click(function(){
            var plan_id = $(this).attr('id');
            var user_id = '<?php echo $_SESSION['id']; ?>';
            getReviewed(plan_id, user_id);
    });
    
    $(".plan_name.execute").click(function(){
        var plan_id = $(this).attr('id');
        var user_id = '<?php echo $_SESSION['id']; ?>';
        getExecuted(plan_id, user_id);
    });
    
    $(".plan_name.review").click(function(){
        var plan_id = $(this).attr('id');
        var user_id = '<?php echo $_SESSION['id']; ?>';
        var content = getReviewed(plan_id, user_id);
    });

</script>
    
</body>
</html>
