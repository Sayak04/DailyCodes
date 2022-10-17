/* eslint-disable default-case */
import React, { useReducer } from 'react';

const reducer = (state, action) => {
    switch (action.type) {
    case 'INCREMENT':
        return {count: state.count + 1, showText: state.showText};
    case 'toggleShowText':
        return {count: state.count, showText: !state.showText};
    default:
        return state;
    }
};

const useReducerHook = () => {
    // useReducer Hook is an alternative for the useState Hook
    // they've the same purpose, when their values are changed they'd redender to show the changed values
    // if we've too many states we can use the useReducer Hook for a global state that'll track the changes globally

    const [state, dispatch] = useReducer(reducer,
        {count: 0, showText : true}
    );

    // const [count, setCount] = useState(0);
    // const [showText, setShowText] = useState(true);

    return (
        <div>
            <h1>{state.count}</h1>
            <button
                onClick={() => {
                    dispatch({ type: 'INCREMENT' });
                    dispatch({ type: 'toggleShowText' });
                }}
            > 
                Click Here
            </button>
            {state.showText && <p>This is a text</p>}
        </div>
    );
}

export default useReducerHook;