const Description = (props) => {
    let { title, subtitle, children } = props;
    return (
        <div className="w-full h-1/2 desc-largep">
            <h1 className="uppercase tracking-wide text-lg text-indigo-500 font-extralight semibold">
                {title}
            </h1>
            <h2 className="block mt-4 text-lg leading-tight font-Karla font-extralight semibold text-red-400 underline">
                {subtitle}
            </h2>
            <p className="mt-3 text-lg text-white">{children}</p>
        </div>
    );
};

export default Description;
