<?php
    include_once('config.php');

if($_SERVER['REQUEST_METHOD'] == "GET"){
    $str = $_GET['q'];

    $select_plans = "select `plan_id`, `name`, `description` from `$db_name`.`plans` where name like '".$str."%'";

    $response = '';
    $result = mysqli_query($conn, $select_plans);
    while ($row = mysqli_fetch_array($result)){
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