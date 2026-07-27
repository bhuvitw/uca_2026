
async function fetchData() {
    try {
        const response = await fetch("http://127.0.0.1:5000/users"); 

        if(!response.ok) {
            throw new error(`HTTP error! Status: ${response.status}`)
        }

        const data = await response.json(); 

        if(!data || data.length == 0){
            throw new error("No user returned from the API")
        }
        
        self.postMessage(data); 

    }catch(err){
        self.postMessage({ error: err.message }); 
    }
}


self.onmessage = function(event){
    const urlFromMainThread = event.data;
    fetchData(urlFromMainThread); 
}