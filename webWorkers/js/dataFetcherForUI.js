const worker2 = new Worker("js/worker.js")

worker2.postMessage("http://127.0.0.1:5000/users");

worker2.onmessage = function (event) {
    const result = event.data; 

    if(result.error){
        console.error("Worker error: ", result.error); 
        document.getElementById("users").innerHTML = "No User Found";
        return ; 
    }

    const userDiv = document.getElementById("users"); 
    
    result.forEach(user => {
        const element = document.createElement("div"); 
        element.id = user.id; 
        const statusText = user.isActive ? "Active" : "Inactive"; 
        element.innerHTML = `${user.name} - ${statusText}`
        userDiv.appendChild(element);
    })
}

worker2.onerror = function (error){
    console.error("Web Worker encountered an error ", error.message); 
}