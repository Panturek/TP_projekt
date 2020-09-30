<?php

if($_SERVER['REQUEST_METHOD'] == "POST"){
    $user_id = file_get_contents('php://input');

    include_once( 'config.php');

    $select_reviewed = "select reviewers.plan_id, plans.name
                        from $db_name.reviewers, $db_name.plans
                        where reviewers.plan_id like plans.plan_id
                        and user_id= ".$user_id;
    $select_executed = "select executives.plan_id, plans.name
                        from $db_name.executives, $db_name.plans
                        where executives.plan_id like plans.plan_id
                        and user_id= ".$user_id;

    $get_reviewed = mysqli_query($conn, $select_reviewed);
    $get_executed = mysqli_query($conn, $select_executed);

    if($get_reviewed){
        $reviewed_plans = mysqli_fetch_all($get_reviewed);
    }
    if($get_executed){
        $executed_plans = mysqli_fetch_all($get_executed);
    }
    
    @mysqli_close($conn);

    $rev_items=[];
    if(isset($reviewed_plans)){
        foreach($reviewed_plans as $key=>$value){
            array_push($rev_items, '["'.$value[0].'", "'.$value[1].'"]');
        }
    }
    $exec_items=[];
    if(isset($executed_plans)){
        foreach($executed_plans as $key=>$value){
            array_push($exec_items, '["'.$value[0].'", "'.$value[1].'"]');
        }
    }
    echo '{ "rev":[ '.implode(',', $rev_items).'], "exec": ['.implode(',', $exec_items).'] }';
}
?>
