<?php
    include_once( $_SERVER['DOCUMENT_ROOT'].'/config.php');

if($_SERVER['REQUEST_METHOD'] == "GET"){
    $str = $_GET['q'];
    $user_id = $_GET['u'];
    
    $select_already_executed = "select distinct plan_id"
                        ." from $db_name.executives"
                        ." where user_id = $user_id";
    
    $result = mysqli_query($conn, $select_already_executed);
    $ommit = [];

    while ($row = $result->fetch_array(MYSQLI_NUM)){
        array_push($ommit, $row[0]);
    }

    $select_plans = "select `plans`.`plan_id`, `plans`.`name`, `plans`.`description`"
                ." from `$db_name`.`plans`"
                ." where `plans`.`name` like '".$str."%'";

    $response = '';
    $result = mysqli_query($conn, $select_plans);
    while ($row = mysqli_fetch_array($result)){
        if( array_search( $row['plan_id'], $ommit ) !== false ){
            continue;
        }

        $line = $row['plan_id'].':'.$row['name'].':'.$row['description'].', ';
        $response = $response.$line;
    }

    if(!$result){
        $response = 'Not found';
    }
    @mysqli_close($conn);
    echo json_encode($response);
}
?>