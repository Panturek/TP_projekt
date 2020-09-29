<?php
include_once( $_SERVER['DOCUMENT_ROOT'].'/config.php');
    
function isJson($string) {
    json_decode($string);
    return (json_last_error() == JSON_ERROR_NONE);
}

function makeStateFile($plan_id, $user_id){

    if ( !is_dir('users/usr'.$user_id) ) {
        mkdir('users/usr'.$user_id, 0777, true);
    }
    
    $plan = json_decode(file_get_contents("plans/$plan_id.json"), true);
    $init_state = $plan['features']['states'][0];
    $tasks = $plan['tasks'];
    $entityBody = '{';

    foreach( $tasks as $key => $value ){
        if($key != 't0'){
            if($entityBody!='{')
                $entityBody = $entityBody.',';
            $entityBody = $entityBody.'"'.$key.'": { "state":"'.$init_state.'","startdate":null,"enddate":null }';
        }
    }
    $entityBody = $entityBody.'}';

    $fp = fopen('users/usr'.$user_id.'/'.$plan_id.'.state.json', 'w');
    fwrite($fp, $entityBody);
    fclose($fp);

    return $entityBody;
}


if($_SERVER['REQUEST_METHOD'] == "POST"){

    $entityBody = file_get_contents('php://input');

    if ( !isJson($entityBody) )
        die("corrupted json file sent");

    $entity = json_decode($entityBody);
    $user_id = $entity->user_id;
    $plan_id = $entity->plan_id;

    $check_redef = "select * from `$db_name`.`executives` where"
                ." `plan_id` like $plan_id"
                ." and `user_id` = $user_id"
                ." and `discharge_date` is null";

    if( mysqli_num_rows(mysqli_query($conn, $check_redef)) > 0 ){
        $response = array("status" => 0, "msg" => "record already exists");
    }
    else{
        $insert_executive = "INSERT INTO `$db_name`.`executives`"
                ." (`plan_id`, `user_id`, `assignment_date`, `discharge_date` )"
                ." VALUES ('$plan_id', '$user_id', now(), null )";
        $result = mysqli_query($conn, $insert_executive);
        if($result){
            $response = array("status" => 1, "msg" => "Plan has been added successfully!");
            $response = makeStateFile($plan_id, $user_id);
        }
        else{
            $response = array("status" => 0, "msg" => "Error adding a Plan!");
            
        }
    }

    @mysqli_close($conn);
    echo json_encode($response);
}

?>