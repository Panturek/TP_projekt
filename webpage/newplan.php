<?php
include_once( $_SERVER['DOCUMENT_ROOT'].'/config.php');
    
function isJson($string) {
    json_decode($string);
    return (json_last_error() == JSON_ERROR_NONE);
}

function add_new_plan($entityBody, $author_id){
    $plan_id = $author_id.date("ymdHis");

    $CHK = 10 - ( array_sum(str_split($plan_id)) % 10 );
    $plan_id = $plan_id.$CHK;
    
    $fp = fopen('plans/'.$plan_id.'.json', 'w');
    fwrite($fp, $entityBody);
    fclose($fp);

    return $plan_id;
}

if($_SERVER['REQUEST_METHOD'] == "POST"){

    $entityBody = file_get_contents('php://input');

    if ( !isJson($entityBody) )
        die("corrupted json file sent");

    $entity = json_decode($entityBody);
    $name = $entity->name;
    $description = $entity->description;
    $author_id = $entity->author;
    $plan_id = add_new_plan(json_encode($entity->plan), $author_id);

    $insert_plan = "INSERT INTO `$db_name`.`plans` (`plan_id`, `name`, `description`, `status` ) VALUES ('$plan_id', '$name', '$description', 'CREATED' );";
    $insert_reviewer = "INSERT INTO `$db_name`.`reviewers` (`plan_id`, `user_id`, `assignment_date`, `discharge_date` ) VALUES ('$plan_id', '$author_id', now(), null );";

    $query_status = mysqli_query($conn, $insert_plan) && mysqli_query($conn, $insert_reviewer);
    if($query_status){
        $response = array("status" => 1, "Success" => "Plan has been added successfully!");
    }
    else{
        $response = array("status" => 0, "Error" => "Error adding a Plan!");
    }
    @mysqli_close($conn);

}
else{
    $response = array("status" => 0, "Error" => "Request method not accepted!");
}

// Set Content-type to JSON
header('Content-type: application/json');
echo json_encode($response);

?>