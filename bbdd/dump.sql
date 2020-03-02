--
-- PostgreSQL database dump
--

-- Dumped from database version 10.10
-- Dumped by pg_dump version 10.10

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: comment; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.comment (
    id_comment integer NOT NULL,
    comment character varying(200) NOT NULL,
    id_user integer NOT NULL,
    id_photo integer NOT NULL
);


ALTER TABLE public.comment OWNER TO postgres;

--
-- Name: comment_id_comment_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.comment_id_comment_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.comment_id_comment_seq OWNER TO postgres;

--
-- Name: comment_id_comment_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.comment_id_comment_seq OWNED BY public.comment.id_comment;


--
-- Name: photo; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.photo (
    id_photo integer NOT NULL,
    url character varying(50) NOT NULL,
    size character varying(50) NOT NULL,
    mg integer NOT NULL,
    id_user integer NOT NULL,
    idstyle integer NOT NULL
);


ALTER TABLE public.photo OWNER TO postgres;

--
-- Name: photo_id_photo_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.photo_id_photo_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.photo_id_photo_seq OWNER TO postgres;

--
-- Name: photo_id_photo_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.photo_id_photo_seq OWNED BY public.photo.id_photo;


--
-- Name: style; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.style (
    id_style integer NOT NULL,
    tipo character varying(50) NOT NULL
);


ALTER TABLE public.style OWNER TO postgres;

--
-- Name: style_id_style_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.style_id_style_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.style_id_style_seq OWNER TO postgres;

--
-- Name: style_id_style_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.style_id_style_seq OWNED BY public.style.id_style;


--
-- Name: usuario; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.usuario (
    id_user integer NOT NULL,
    name character varying(50) NOT NULL,
    email character varying(50) NOT NULL,
    password text NOT NULL
);


ALTER TABLE public.usuario OWNER TO postgres;

--
-- Name: usuario_id_user_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.usuario_id_user_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.usuario_id_user_seq OWNER TO postgres;

--
-- Name: usuario_id_user_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.usuario_id_user_seq OWNED BY public.usuario.id_user;


--
-- Name: comment id_comment; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.comment ALTER COLUMN id_comment SET DEFAULT nextval('public.comment_id_comment_seq'::regclass);


--
-- Name: photo id_photo; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.photo ALTER COLUMN id_photo SET DEFAULT nextval('public.photo_id_photo_seq'::regclass);


--
-- Name: style id_style; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.style ALTER COLUMN id_style SET DEFAULT nextval('public.style_id_style_seq'::regclass);


--
-- Name: usuario id_user; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.usuario ALTER COLUMN id_user SET DEFAULT nextval('public.usuario_id_user_seq'::regclass);


--
-- Data for Name: comment; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.comment (id_comment, comment, id_user, id_photo) FROM stdin;
2	Esta guapa	2	15
3	aa	2	15
4	hola	2	15
5	jaja	2	15
6	hola	2	15
7	me gusta	2	15
8	Eres muy fea	3	15
\.


--
-- Data for Name: photo; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.photo (id_photo, url, size, mg, id_user, idstyle) FROM stdin;
2	kk	123	0	15	2
3	kk	123	0	15	2
4	kk	123	0	15	2
5	ññ	123	0	15	1
6	aa	123	0	15	3
7	aa	123	0	15	3
8	aa	123	0	15	3
9	sss	123	0	15	4
10	hhh	123	0	15	1
\.


--
-- Data for Name: style; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.style (id_style, tipo) FROM stdin;
1	roquero
2	casual
3	clasico
4	hipster
\.


--
-- Data for Name: usuario; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.usuario (id_user, name, email, password) FROM stdin;
15	Pepa	Pepa@gmail.com	$2a$06$iwKlEWb.8oC.cgPTkqpfWu.yz1WwvNZVmk4t5YMMRLgepy.SnaXF2
25			$2a$06$aFHZgm8LX0JYBIv76ewnw.nZ73P08So6tmYqcVQ.c1iEZS3hQejwS
\.


--
-- Name: comment_id_comment_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.comment_id_comment_seq', 8, true);


--
-- Name: photo_id_photo_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.photo_id_photo_seq', 10, true);


--
-- Name: style_id_style_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.style_id_style_seq', 4, true);


--
-- Name: usuario_id_user_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.usuario_id_user_seq', 25, true);


--
-- Name: comment comment_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.comment
    ADD CONSTRAINT comment_pkey PRIMARY KEY (id_comment);


--
-- Name: photo photo_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.photo
    ADD CONSTRAINT photo_pkey PRIMARY KEY (id_photo);


--
-- Name: style style_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.style
    ADD CONSTRAINT style_pkey PRIMARY KEY (id_style);


--
-- Name: usuario usuario_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.usuario
    ADD CONSTRAINT usuario_pkey PRIMARY KEY (id_user);


--
-- Name: photo photo_id_user_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.photo
    ADD CONSTRAINT photo_id_user_fkey FOREIGN KEY (id_user) REFERENCES public.usuario(id_user);


--
-- Name: photo photo_idstyle_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.photo
    ADD CONSTRAINT photo_idstyle_fkey FOREIGN KEY (idstyle) REFERENCES public.style(id_style);


--
-- PostgreSQL database dump complete
--

