<?php

if($_SERVER['REQUEST_METHOD'] == "POST"){

    $entityBody = file_get_contents('php://input');
    $json = json_decode($entityBody, true);
    if (json_last_error() == JSON_ERROR_NONE) {
        $plan_id = $json['plan_id'];
        $user_id = $json['user_id'];
        $task_id = $json['task_id'];
        $state = $json['state'];
        $file_path = 'users/usr'.$user_id.'/'.$plan_id.'.state.json';
        $fp = file_get_contents($file_path, 'r');
        $data = json_decode($fp, true);
        $data[$task_id]['state'] = $state;
        $new_file = json_encode( $data );
        file_put_contents($file_path, $new_file);
        echo $new_file; 
        
    }
    else{
        echo '{
            "status":"json corrupted"
        }';
    }
}
?>
