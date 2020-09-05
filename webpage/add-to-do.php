<?php

function isJson($string) {
    json_decode($string);
    return (json_last_error() == JSON_ERROR_NONE);
}

include_once('config.php');

if($_SERVER['REQUEST_METHOD'] == "POST"){

    $entityBody = file_get_contents('php://input');
    
    if ( isJson($entityBody) ){
        $fp = fopen('plans/test_post_received.json', 'w');
        fwrite($fp, $entityBody);
        fclose($fp);
    }
    else{
        echo "plan file format corrupted";
    }
    // Get data from the REST client
    $task = isset($_POST['task']) ? mysqli_real_escape_string($conn, $_POST['task']) : "";
    $date = isset($_POST['date']) ? mysqli_real_escape_string($conn, $_POST['date']) : "";
    $priority = isset($_POST['priority']) ? mysqli_real_escape_string($conn, $_POST['priority']) : "";
    // Insert data into database
    $sql = "INSERT INTO `tpprojekt`.`rest_tasks` (`task`, `date`, `priority`) VALUES ('$task', '$date', '$priority');";
    $post_data_query = mysqli_query($conn, $sql);
    if($post_data_query){
        $json = array("status" => 1, "Success" => "To-Do has been added successfully!");
    }
    else{
        $json = array("status" => 0, "Error" => "Error adding To-Do! Please try again!");
    }
}
else{
    $json = array("status" => 0, "Info" => "Request method not accepted!");
}

$fp = fopen('plans/test_plan.json', 'w');
fwrite($fp, json_encode($json));
fclose($fp);


@mysqli_close($conn);
// Set Content-type to JSON
header('Content-type: application/json');
echo json_encode($json);

?>