const Attribute = (props) => {
    return (
        <div className="transition ease-in-out hover:-translate-y-2 hover:scale-105 duration-300 underline decoration-indigo-500 underline-offset-8 decoration-4 pt-16 pb-16 flex flex-row items-center whitespace-nowrap">
            <h1 className=" text-white text-2xl attribute1">{props.first}</h1>
            <h1 className=" pl-4 pr-4 text-white text-2xl attribute1">-</h1>
            <h1 className=" text-white text-2xl attribute1">{props.second}</h1>
        </div>
    );
};

export default Attribute;
