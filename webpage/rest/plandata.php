<?php

if($_SERVER['REQUEST_METHOD'] == "POST"){

    $entityBody = file_get_contents('php://input');
    $json = json_decode($entityBody, true);
    if (json_last_error() == JSON_ERROR_NONE) {
        $plan_id = $json['plan_id'];
        $fp = file_get_contents('plans/'.$plan_id.'.json', 'r');
        echo $fp;
    }
    else{
        echo '{
            "status": "json corrupted" 
        }';
    }
}
?>
