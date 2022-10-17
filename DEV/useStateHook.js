import React, { useState } from 'react';

const useStateHook = () => {
    const [counter, setCounter] = useState(0);
    const [inputValue, setInputValue] = useState("Sayak");

    const incrementCounter = () => {
        setCounter(counter + 1);
    }
    const decrementCounter = () => {
        setCounter(counter - 1);
    }
    const changeText = (event) => {
        const newValue = event.target.value;
        setInputValue(newValue);
    }
    return (
        <>
            <div>
                <button onClick={decrementCounter}>
                    Decrement
                </button>
                {" "}
                {counter}
                {" "}
                <button onClick={incrementCounter}>
                    Increment
                </button>
                <br />
                {inputValue}
                <input placeholder='Enter something here...' onChange={changeText}/>
            </div>
        </>
    );
}

export default useStateHook;