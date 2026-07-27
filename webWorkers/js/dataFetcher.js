const webWorker = new Worker("js/worker.js");

webWorker.postMessage("http://127.0.0.1:5000/users");

webWorker.onmessage = function (event) {
    const  result = event.data;

    if(result.error){
        console.error("Worker error: ", result.error); 
        return; 
    }

    result.forEach(user => {
        const statusText = user.isActive ? "Active" : "Inactive" ;
        console.log(`${user.name} - ${statusText}`)
    })
}

webWorker.onerror = function(error) {
    console.error("Web Worker encountered an error ", error.message); 
}



